#include <iostream>
#include <queue>
using namespace std;

#define MAX 51

int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int M, N, K;

void dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
		if (map[nx][ny] == 0 || visit[nx][ny])continue;
		dfs(nx, ny);
	}

}


int main() {

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {

		cin >> M >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = false;
				map[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}