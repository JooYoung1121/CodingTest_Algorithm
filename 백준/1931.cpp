#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, Result = 0;

struct cmp {
	bool operator()(p a, p b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}

};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	priority_queue<p, vector<p>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	p first = pq.top();
	pq.pop();

	Result++;
	int End = first.second;

	while (!pq.empty()) {
		p tmp = pq.top();
		pq.pop();
		if (End <= tmp.first) {
			Result++;
			End = tmp.second;
		}
	}

	cout << Result;
	
	system("pause");
	return 0;
}