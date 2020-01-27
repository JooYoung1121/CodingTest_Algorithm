#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;

	priority_queue<int, vector<int>, less<int>> pq;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		if (dates[idx] == i) {
			pq.push(supplies[idx]);
			if(idx != supplies.size()-1)
				idx++;
		}

		if (stock == 0) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		stock--;
	}

	return answer;
}

int main() {
	int stock, k;
	vector<int> dates, supplies;

	int N;

	cin >> N;

	cin >> stock;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		dates.push_back(d);
	}

	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		supplies.push_back(s);
	}

	cin >> k;

	cout << solution(stock, dates, supplies, k);

	system("pause");
	return 0;
}