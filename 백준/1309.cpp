#include <iostream>
#include <Windows.h>
using namespace std;

#define MOD 9901
#define MAX 100001

int D[MAX][3];

// D[i] = D[i-1]*2 + D[i-2] 이것도 가능

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	D[0][0] = 1;
	D[0][1] = 0;
	D[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2])%MOD;
		D[i][1] = (D[i - 1][0] + D[i - 1][2])%MOD;
		D[i][2] = (D[i - 1][0] + D[i - 1][1])%MOD;
	}

	cout << (D[N][0] + D[N][1] + D[N][2])%MOD;


	system("pause");
	return 0;

}