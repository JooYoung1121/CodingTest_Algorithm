#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

//segment tree or index tree(binary tree)

#define MAX 1000000
int tree_size;
int ret;

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long query(vector<long long> &tree, int node, int start, int end, int k)
{
	if ((start == end) && ret == 0)
	{
		cout << start << "\n";
		return start;
	}

	// 자신의 왼쪽 자식 노드가 k개 이상 가지고 있다면 왼쪽으로 탐색
	if (ret == 0 && (node * 2 <= tree_size && tree[node * 2] >= k))
		return ret = query(tree, node * 2, start, (start + end) / 2, k);

	k -= tree[node * 2];

	// 그 외에는 오른쪽 자식 노드로 탐색
	if (ret == 0 && (node * 2 + 1 <= tree_size && tree[node * 2 + 1] >= k))
		return ret = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, k);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int height = (int)ceil(log2(MAX));

	tree_size = 1 << (height + 1);

	vector<long long> tree(tree_size);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int A;

		cin >> A;

		if (A == 1) {
			int B;
			cin >> B;

			int index = query(tree, 1, 0, MAX - 1, B);
			ret = 0;
			update(tree, 1, 0, MAX - 1, index, -1);
		}
		else {
			long long B, C;

			cin >> B >> C;

			update(tree, 1, 0, MAX - 1, B, C);
		}
	}


	return 0;
}