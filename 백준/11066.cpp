#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int _max = 100000001;

int dp[502][502];

int sum[502];

int result[502];

int main() {
	int T,K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		for (int j = 1; j <= K; j++) {
			int file_size;
			cin >> file_size;
			sum[j] = sum[j - 1] + file_size;
		}

		for (int k = 1; k < K; k++) {
			for (int m = 1; m <= K - k; m++) {
				dp[m][m + k] = _max;
				for (int n = m; n < m + k; n++) {
					dp[m][m + k] = min(dp[m][m + k], dp[m][n] + dp[n + 1][m + k]);
				}
				dp[m][m + k] += sum[m + k] - sum[m - 1];
			}
		}
		result[i] = dp[1][K];
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}

	return 0;
}