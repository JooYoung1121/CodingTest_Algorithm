#include <iostream>
#include <Windows.h>
using namespace std;

int visit[51][51];
int map[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int W, H;

void dfs(int x, int y) {
	int nx, ny;
	visit[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= H+1 || nx <= 0 || ny >= W+1 || ny <= 0) {
			continue;
		}

		if (visit[nx][ny] == 0 && map[nx][ny] == 1)
			dfs(nx, ny);
	}
}

int main() {


	while (1) {
		cin >> W >> H;

		int cnt = 0;

		if (W == 0 && H == 0)
			break;

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				visit[i][j] = 0;
			}
		}

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";


	}



	system("pause");
	return 0;
}