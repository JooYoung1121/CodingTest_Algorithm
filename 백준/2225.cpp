#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 1000000000

int D[201][201]; // N°ú K

int main() {
	int N, K;

	cin >> N >> K;
	
	for (int i = 1; i <= K; i++) {
		D[0][i] = 1;
		D[i][1] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			D[i][j] = (D[i - 1][j] + D[i][j - 1])%MAX;
		}
	}

	cout << D[N][K]%MAX;
	system("pause");

	return 0;
}