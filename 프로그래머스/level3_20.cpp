#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	if (n == 1) {
		answer.push_back(n);
		return answer;
	}

	if (n > s) {
		answer.push_back(-1);
		return answer;
	}
	int start = s / n;
	int mod = s % n;

	for (int i = 1; i <= n; i++) {
		if (i > n - mod) answer.push_back(start+1);
		else answer.push_back(start);
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {

	int N, S;

	cin >> N >> S;

	vector<int> result = solution(N, S);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	system("pause");
	return 0;
}