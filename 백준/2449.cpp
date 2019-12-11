#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

#define MAX 200

int bulb[MAX];

int D[MAX][MAX];

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> bulb[i];
		for (int j = i; j--;) {
			D[j][i] = 1e9;
			for (int k = j; k < i; k++) {
				D[j][i] = min(D[j][i], D[j][k] + D[k + 1][i] + (bulb[k + 1] != bulb[j]));
			}
		}

	}

	cout << D[0][N - 1];



	system("pause");
	return 0;
}