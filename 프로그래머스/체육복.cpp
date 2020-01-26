#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	for (int i = 0; i < lost.size(); i++) {
		cnt[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		cnt[reserve[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == -1) {
			if (cnt[i - 1] == 1)
			{
				cnt[i - 1] = 0;
				cnt[i] = 0;
			}
			else if (cnt[i + 1] == 1) {
				cnt[i + 1] = 0;
				cnt[i] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] != -1)
			answer++;
	}

	return answer;
}

int main() {
	int n;
	vector<int> lost, reserve;

	int a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		lost.push_back(c);
	}

	for (int i = 0; i < b; i++) {
		int d;
		cin >> d;
		reserve.push_back(d);
	}

	cout << solution(n, lost, reserve);



	system("pause");
	return 0;
}