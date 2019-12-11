#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 2001

int num[MAX];
int D[MAX][MAX];

int solve(int x, int y) {
	int& ret = D[x][y];

	if (x == y) {
		ret = 1;
		return ret;
	}
	if (ret != -1) return ret;



	if (num[y] == num[x]) {
		if (x + 1 == y) {
			ret = 1;
		}
		else
			ret = solve(x + 1, y - 1);
	}
	else {
		ret = 0;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;

	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			solve(i, j);
		}
	}


	int M;

	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;

		cin >> S >> E;

		cout << D[S][E] << "\n";
	}


	system("pause");

	return 0;
}