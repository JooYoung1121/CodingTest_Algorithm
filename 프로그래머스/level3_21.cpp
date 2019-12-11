#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	
	priority_queue<int> pq;

	for (int i = 0; i < works.size(); i++) {
		pq.push(works[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (pq.top() > 0) {
			int tmp = pq.top();
			pq.pop();
			pq.push(tmp - 1);
		}
	}
	
	while (!pq.empty()) {
		answer += pq.top() * pq.top();
		pq.pop();
	}

	return answer;
}

int main() {

	int N;

	cin >> N;

	int M;

	cin >> M;

	vector<int> works;

	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;
		works.push_back(w);
	}

	cout << solution(N, works);



	system("pause");
	return 0;
}