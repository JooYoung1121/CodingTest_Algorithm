#include <iostream>
using namespace std;

//segment tree or index tree(binary tree)

#define NUM_MAX 4000000
#define MAX 10001

long long tree[NUM_MAX];
int num[NUM_MAX];
long long result[MAX];


long long init(int index, int start, int end) {
	if (start == end) 
		tree[index] = num[start]; 
		
	else
		tree[index] =
		init(2 * index, start, (start + end) / 2) +
		init(2 * index + 1, (start + end) / 2 + 1, end);

	return tree[index];
}

long long sum(int index, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && right >= end) {
		return tree[index];
	}
	int mid = (start + end) / 2;
	return sum(2*index, start, mid, left,right) + sum(2*index + 1, mid+1, end, left, right);
}

void update(int index, int start, int end, int node, int val) {
	
	if (node > end || node < start) {
		return;
	}

	tree[index] += val;
	if (start == end) return;
	int mid = (start + end) / 2;

	update(2 * index, start, mid, node, val);
	update(2 * index + 1, mid + 1, end, node, val);
}

int main() {
	int N, M, K;
	
	cin >> N >> M >> K;

	

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int _count = 0;

	init(1, 0, N - 1);

	int A, B, C;
	for (int i = 0; i < M + K; i++) {
		cin >> A >> B >> C;
		if (A == 1) {
			update(1, 0, N - 1, B-1, (C - num[B-1]));
			num[B - 1] = C;
		}
		else {
			result[_count] = sum(1, 0, N - 1, B - 1, C - 1);
			_count++;
		}
	}

	for (int i = 0; i < _count; i++) {
		cout << result[i] << endl;
	}
	

	return 0;
}