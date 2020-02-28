#include <iostream>
using namespace std;

#define MAX 1001

long long DP[MAX][MAX];

int main() {

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		DP[i][1] = i % 10007;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			DP[i][j] = DP[i - 1][j - 1]%10007 + DP[i - 1][j]%10007;
			DP[i][j] = DP[i][j] % 10007;
			if (i == N && j == K) {
				cout << DP[i][j] << endl;
				return 0;
			}
		}
	}

	if (K == 0) {
		cout << 1 << endl;
	}
	else {
		cout << N << endl;
	}


	return 0;
}