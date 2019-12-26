#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int low = 0;
	int high = M;
	long long _max = 0;

	long long sum = 0;
	int tmp = 0;
	for (int i = 0; i < budgets.size(); i++) {
		sum += budgets[i];
		tmp = max(tmp, budgets[i]);
	}

	if (sum <= M)
	{
		answer = tmp;
		return answer;
	}

	while (low < high) {
		int mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < budgets.size(); i++) {
			int cost;
			if (mid >= budgets[i])
				cost = budgets[i];
			else {
				cost = mid;
			}
			sum += cost;
		}

		if (sum > M) {
			high = mid;
		}
		else {
			if (_max <= sum) {
				_max = sum;
				answer = mid;
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
	}

	return answer;
}

int main() {
	int N;

	cin >> N;

	vector<int> budgets;

	for (int i = 0; i < N; i++) {
		int bu;
		cin >> bu;
		budgets.push_back(bu);
	}
	int M;

	cin >> M;

	cout << solution(budgets, M);



	system("pause");
	return 0;
}