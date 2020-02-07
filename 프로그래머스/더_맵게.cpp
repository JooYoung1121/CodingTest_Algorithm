#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	if (scoville.size() == 1) {
		if (scoville[0] < K)
			return -1;
		return answer;
	}

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (!pq.empty()) {

		if (pq.size() == 1) {
			if (pq.top() < K)
				answer = -1;
			break;
		}
		int first = pq.top();
		if (first >= K)
			break;
		pq.pop();
		int second = pq.top();
		pq.pop();

		int Shake = first + (second * 2);
		pq.push(Shake);

		answer++;
	}



	return answer;
}

int main() {

	vector<int> scoville;
	int N,K;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		scoville.push_back(a);
	}
	cin >> K;

	cout << solution(scoville, K);

	system("pause");
	return 0;
}