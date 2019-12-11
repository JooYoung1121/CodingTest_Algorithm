#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001

int cnt[MAX];

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	int cnt = 0;

	for (int i = 0; i < prices.size(); i++) {
		cnt = 0;
		for (int j = i+1; j < prices.size(); j++) {
			if (prices[i] <= prices[j]) {
				cnt++;
			}
			else {
				cnt++;
				break;
			}
		}
		answer.push_back(cnt);
	}


	return answer;
}

int main() {
	int N;

	cin >> N;

	vector<int> prices;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		prices.push_back(p);
	}

	vector<int> result = solution(prices);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;
}