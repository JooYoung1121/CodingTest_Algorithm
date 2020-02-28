#include <iostream>
using namespace std;

#define MAX 1025

int D[MAX][MAX];
int num[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N, M;

	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num[i][j];
			if (i == 1) {
				sum += num[i][j];
				D[1][j] = sum;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = D[i][j - 1] + D[i-1][j] - D[i-1][j-1] + num[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int result;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		result = D[c][d] - D[a - 1][d] - D[c][b - 1] + D[a - 1][b - 1];
		cout << result << "\n";
	}


	return 0;
}