#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MOD 1000000007
#define MAX 101

int D[MAX][MAX];


int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	
	for (int i = 0; i < puddles.size(); i++) {
		D[puddles[i][0]][puddles[i][1]] = -1;
	}
	for (int i = 2; i <= m; i++) {
		if (D[i][1] == -1)
			break;
		else
			D[i][1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (D[1][i] == -1)
			break;
		else
			D[1][i] = 1;
	}

	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (D[i][j] == -1)
				continue;

			if (D[i - 1][j] == -1)
				D[i][j] = D[i][j - 1] % MOD;
			else if (D[i][j - 1] == -1)
				D[i][j] = D[i - 1][j] % MOD;
			else
				D[i][j] = (D[i - 1][j] + D[i][j - 1])%MOD;
		}
	}

	answer = D[m][n]%MOD;


	return answer;
}


int main() {
	int M, N;
	cin >> M >> N;

	int p;
	cin >> p;

	vector<vector<int>> puddles;

	for (int i = 0; i < p; i++) {
		vector<int> tmp;
		int x, y;
		cin >> x >> y;

		tmp.push_back(x);
		tmp.push_back(y);

		puddles.push_back(tmp);
	}

	cout << solution(M, N, puddles);

	system("pause");
	return 0;
}