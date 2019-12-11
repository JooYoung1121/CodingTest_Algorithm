#include <iostream>
using namespace std;

int num[101];

long long D[101][21];

int main() {
	int N;
	int answer;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> num[i];
	}
	cin >> answer;

	D[0][num[0]] = 1;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (D[i - 1][j] != 0) {
				if (j + num[i] <= 20) {
					D[i][j + num[i]] += D[i - 1][j];
				}
				if (j - num[i] >= 0) {
					D[i][j - num[i]] += D[i - 1][j];
				}
			}
		}
	}

	cout << D[N - 2][answer];

	return 0;
}