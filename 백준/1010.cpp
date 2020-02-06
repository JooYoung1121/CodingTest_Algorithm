#include <iostream>
using namespace std;

long long D[33][33];

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;

		cin >> N >> M;
		
		for (int i = 1; i <= M; i++) {
			D[i][1] = i;
		}

		int x, y;

		for (int i = 2; i <= M; i++) {
			for (int j = 2; j <= i; j++) {
				D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
			}
		}

		cout << D[M][N] << endl;

	}


	return 0;
}