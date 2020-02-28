#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
#define COST_MAX 10001


int memory[MAX];
int cost[MAX];
int D[MAX][COST_MAX];


int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= COST_MAX; j++) {
			if (j >= cost[i]) {
				D[i][j] = max(D[i - 1][j], D[i - 1][j - cost[i]] + memory[i]);
			}
			else {
				D[i][j] = D[i - 1][j];
			}
		}
	}
	int result = 10002;
	for (int i = 0; i <= COST_MAX; i++) {
		if (D[N][i] >= M) {
			result = min(result, i);
			break;
		}
	}

	cout << result;

	return 0;
}