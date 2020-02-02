#include <iostream>
#include <vector>
using namespace std;

#define MAX 26

typedef struct tree {
	char left;
	char right;
}T;

T TREE[MAX];
int N;

void pre_order(char node) {
	if (node == '.') {
		return;
	}
	else {
		cout << node;
		pre_order(TREE[node].left);
		pre_order(TREE[node].right);
	}
}

void in_order(char node) {
	if (node == '.') {
		return;
	}
	else {
		in_order(TREE[node].left);
		cout << node;
		in_order(TREE[node].right);
	}
}

void post_order(char node) {
	if (node == '.') {
		return;
	}
	else {
		post_order(TREE[node].left);
		post_order(TREE[node].right);
		cout << node;
	}

}

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		TREE[a].left = b;
		TREE[a].right = c;
	}

	pre_order('A');
	cout << endl;
	in_order('A');
	cout << endl;
	post_order('A');
	cout << endl;


	return 0;
}