#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BUS_MAX 100001
#define MAX 101
#define INF 987654321

typedef struct root {
	int to;
	int cost;
}R;

vector<R> BUS[BUS_MAX];

int D[MAX][MAX];

int main() {
	int N, M;

	cin >> N >> M;
	int A, B, C;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		R tmp;
		tmp.to = B;
		tmp.cost = C;
		BUS[A].push_back(tmp);
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == j) {
				D[i][j] = 0;
			}
			else {
				D[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < BUS[i].size(); j++) {
			if (D[i][BUS[i][j].to] != INF) {
				D[i][BUS[i][j].to] = min(D[i][BUS[i][j].to], BUS[i][j].cost);
			}
			else {
				D[i][BUS[i][j].to] = BUS[i][j].cost;
			}
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][j] > D[i][k] + D[k][j]){
						D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] >= INF)
				cout << 0 << ' ';
			else {
				cout << D[i][j] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}

