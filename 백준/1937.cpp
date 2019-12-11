#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

#define MAX 501

int forest[MAX][MAX];

int D[MAX][MAX];

int N;

int solve(int x, int y) {
	int &ret = D[x][y];

	if (ret != 1) return ret;

	if (forest[x][y] < forest[x-1][y] && x>1) { // up
		ret = max(solve(x-1, y)+1, ret);
	}
	if (forest[x][y] < forest[x+1][y] && x < N) { // down
		ret = max(solve(x+1, y) + 1, ret);
	}
	if (forest[x][y] < forest[x][y-1] && y > 1) { // left
		ret = max(solve(x, y-1) + 1, ret);
	}
	if (forest[x][y] < forest[x][y+1] && y < N) { // right
		ret = max(solve(x, y+1) + 1, ret);
	}

	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> forest[i][j];
			D[i][j] = 1;
		}
	}
	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result = max(solve(i, j), result);
		}
	}

	cout << result;
	system("pause");
	return 0;

}