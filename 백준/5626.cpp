#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001
#define MOD 1000000007

long long stone[MAX];
long long D[2][MAX]; // 1은 현재 위치 0은 이전 위치 값들 

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stone[i];
	}

	if(stone[1] < 1)
		D[0][0] = 1;
	else {
		D[0][0] = 0;
	}


	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < MAX; j++) {
			D[1][j] = 0;
		}
		if (stone[i] == -1) {
			D[1][0] = (D[0][0] + D[0][1]) % MOD;
			for (int j = 1; j <= MAX/2; j++) {
				D[1][j] = (D[0][j - 1] + D[0][j] + D[0][j + 1]) % MOD;
			}
		}
		else if (stone[i] == 0) {
			D[1][stone[i]] = (D[0][stone[i]] + D[0][stone[i] + 1]) % MOD;
		}
		else {
			D[1][stone[i]] = (D[0][stone[i] - 1] + D[0][stone[i]] + D[0][stone[i] + 1]) % MOD;
		}
		swap(D[1], D[0]);
	}

	cout << D[0][0];

	return 0;
}