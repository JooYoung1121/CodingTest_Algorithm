#include <iostream>
using namespace std;

//segment tree or index tree(binary tree)

#define NUM_MAX 400001
#define MAX 100001

long long tree[NUM_MAX];
long long num[NUM_MAX];
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
	} // 범위에서 벗어나면 0
	if (left <= start && right >= end) {
		return tree[index];
	} // 범위내에 있으면 리턴
	int mid = (start + end) / 2;
	return sum(2 * index, start, mid, left, right) + sum(2 * index + 1, mid + 1, end, left, right);
}

void update(int index, int start, int end, int node, long long val) {

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	int _count = 0;
	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	init(1, 0, N - 1);

	int x, y, a;
	long long b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;

		if (x > y) {
			result[_count] = sum(1, 0, N - 1, y-1, x-1);
		}
		else {
			result[_count] = sum(1, 0, N - 1, x-1, y-1);
		}
		long long dif = b - num[a - 1];
		update(1, 0, N - 1, a-1, dif);
		num[a - 1] = b;
		
		_count++;
	}

	for (int i = 0; i < _count; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}