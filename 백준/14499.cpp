#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[21][21];

int direct[4][6] = {
	{ 2, 1, 5, 0, 4, 3 },
{ 3, 1, 0, 5, 4, 2 },
{ 4, 0, 2, 3, 5, 1 },
{ 1, 5, 2, 3, 0, 4 }
};

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0}; // right left up down

int N, M, x, y, K;

int dice[6];
int tmp[6];

void solve() {

	while (K--) {
		int d;
		cin >> d; // πÊ«‚/
		d--;

		x += dx[d];
		y += dy[d];

		if (x < 0 || x >= N || y < 0 || y >= M) {
			x -= dx[d];
			y -= dy[d];
			continue;
		}

		for (int i = 0; i < 6; i++) {
			tmp[i] = dice[i];
		}

		for (int i = 0; i < 6; i++) {
			dice[i] = tmp[direct[d][i]];
		}

		if (map[x][y] != 0) {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		else
			map[x][y] = dice[5];

		cout << dice[0] << endl;
	}

}

int main() {
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	
	system("pause");
	return 0;
}