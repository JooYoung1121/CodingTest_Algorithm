#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

long long prime[101];

map<long long, int> _check;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int K, N;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> prime[i];
	}

	long long _max = 0;
	int count = 0;
	pq.push(1);

	while (N) {
		long long front = pq.top();
		pq.pop();

		count++;
		
		for (int i = 0; i < K; i++) {
			long long v = front * prime[i];

			if (pq.size()> N && _max < v)
				break;
			if (_check[v] == 0) {
				_max = max(_max, v);
				_check[v] = 1;
				pq.push(v);
			}
		}
		N--;
	}
	cout << pq.top() << "\n";

	return 0;
}