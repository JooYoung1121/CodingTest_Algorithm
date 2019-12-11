#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;

#define MAX 5001

#define MOD 1000000

int num[MAX];
int D[MAX];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string N;

	getline(cin, N);

	for (int i = 1; i <= N.length(); i++) {
		num[i] = N[i - 1] - '0';
	}

	if (num[1] == 0) {
		cout << 0;
		return 0;
	}
	D[0] = 1;
	D[1] = 1;

	for (int i = 2; i <= N.length(); i++) {
		if (num[i] > 0) {
			D[i] = D[i - 1] % MOD;
		}

		int x = num[i - 1] * 10 + num[i];

		if (x >= 10 && x <= 26) {
			D[i] = (D[i] + D[i - 2]) % MOD;
		}
	}

	cout << D[N.length()]%MOD;	

	system("pause");
	return 0;
}