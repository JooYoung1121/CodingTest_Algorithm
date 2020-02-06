#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int num, x;
	struct node* left;
	struct node* right;
};

struct info {
	int x, y, num;
};
vector<vector<int>> answer;

struct cmp {
	bool operator()(info a, info b) {
		if (a.y == b.y) {
			return a.x > b.x;
		}
		return a.y < b.y;
	}
};

void find(node* cur,node* newnode) {
	if (cur->x > newnode->x && cur->left != NULL) { //현재 노드보다 왼쪽인데 이미 왼쪽 자식 노드 존재
		find(cur->left, newnode);
	}
	else if (cur->x > newnode->x && cur->left == NULL) {
		cur->left = newnode;
	}
	else if (cur->x < newnode->x && cur->right != NULL) {
		find(cur->right, newnode);
	}
	else {
		cur->right = newnode;
	}
}

void preorder(node *curr) {
	if (curr == NULL)
		return;
	answer[0].push_back(curr->num);
	preorder(curr->left);
	preorder(curr->right);
}
void postorder(node *curr) {
	if (curr == NULL)
		return;
	postorder(curr->left);
	postorder(curr->right);
	answer[1].push_back(curr->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	answer.resize(2);

	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 0; i < nodeinfo.size(); i++) {
		info tmp;
		tmp.x = nodeinfo[i][0];
		tmp.y = nodeinfo[i][1];
		tmp.num = i + 1;
		pq.push(tmp);
	}

	info cur;
	node* newnode;
	node* root;


	cur = pq.top();
	pq.pop();
	newnode = new node;
	newnode->num = cur.num;
	newnode->x = cur.x;
	newnode->left = NULL;
	newnode->right = NULL;
	root = newnode;

	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		newnode = new node;
		newnode->num = cur.num;
		newnode->x = cur.x;
		newnode->left = NULL;
		newnode->right = NULL;
		find(root, newnode);
	}

	preorder(root);
	postorder(root);

	return answer;
}

int main() {

	int N;

	cin >> N;
	
	vector<vector<int>> nodeinfo;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int i = 0; i < 2; i++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		nodeinfo.push_back(tmp);
	}

	vector<vector<int>> result = solution(nodeinfo);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}