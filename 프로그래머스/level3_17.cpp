#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long solution(int n, vector<int> times) {
	long long answer = 0;

	long long _max = *max_element(times.begin(),times.end());

	long long right = n*_max;
	long long left = 1;

	answer = right;

	while (left <= right) {
		long long mid = (right + left) / 2;

		int cnt = 0;

		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}

		if (cnt < n) left = mid + 1;
		else {
			if (mid <= answer)
				answer = mid;
			right = mid - 1;
		}
	}

	return answer;
}

int main() {
	int N, M;

	cin >> N >> M;

	vector<int> times;

	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;

		times.push_back(t);
	}

	cout << solution(N, times);



	system("pause");
	return 0;
}