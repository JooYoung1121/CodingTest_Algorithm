#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

int dp[10001];

int main() {
	int N;

	cin >> N;
	int result = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 0;
		int a, b;
		cin >> a >> b;

		for (int j = 0; j < b; j++) {
			int x;
			cin >> x;

			dp[i] = max(dp[i], dp[x]);
		}
		dp[i] += a;
		result = max(result, dp[i]);
	}

	cout << result;

	system("pause");
	return 0;
}