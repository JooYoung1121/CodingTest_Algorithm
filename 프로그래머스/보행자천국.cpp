#include <iostream>
#include <vector>
using namespace std;

#define MOD 20170805
#define MAX 501

int R[MAX][MAX]; // right
int D[MAX][MAX]; // down
int M, N;

int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	memset(R, 0, sizeof(R));
	memset(D, 0, sizeof(D));
	R[1][1] = 1;
	D[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (city_map[i - 1][j - 1] == 0) {
				R[i][j] = (R[i][j] + R[i][j - 1] + D[i - 1][j]) % MOD;
				D[i][j] = (D[i][j] + R[i][j - 1] + D[i - 1][j]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1) {
				R[i][j] = 0;
				D[i][j] = 0;
			}
			else {
				R[i][j] = R[i][j - 1];
				D[i][j] = D[i - 1][j];
			}
		}
	}

	answer = (R[m][n])%MOD;

	return answer;
}

int main() {

	cin >> M >> N;

	vector<vector<int>> city_map;

	for (int i = 0; i < M; i++) {
		vector<int> tmp;

		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		city_map.push_back(tmp);
	}

	cout << solution(M, N, city_map);

	system("pause");
	return 0;
}