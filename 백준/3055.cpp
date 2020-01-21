#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;

#define MAX 51

char map[MAX][MAX];
p start_idx, end_idx;	
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<p> water;
int water_check[MAX][MAX];
int time_check[MAX][MAX];
int R, C;


void water_bfs() {
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;

			if (water_check[nx][ny] == 0 && map[nx][ny] == '.')
			{
				water_check[nx][ny] = water_check[x][y] + 1;
				water.push({ nx,ny });
			}
		}
	}
}

void bfs() {
	queue<p> q;

	q.push(start_idx);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;


			if (time_check[nx][ny] == 0 && (map[nx][ny] == '.' || map[nx][ny] == 'D')) {
				if (water_check[nx][ny] == 0)
				{
					time_check[nx][ny] = time_check[x][y] + 1;
					q.push({ nx,ny });
				}
				else {
					if (water_check[nx][ny] > time_check[x][y] + 1) {
						time_check[nx][ny] = time_check[x][y] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}


int main() {
	

	cin >> R >> C;

	

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D')
			{
				end_idx = {i,j};
			}
			if (map[i][j] == 'S') {
				start_idx = { i,j };
			}
			if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}

	water_bfs();
	bfs();

	if (time_check[end_idx.first][end_idx.second] != 0)
		cout << time_check[end_idx.first][end_idx.second];
	else
		cout << "KAKTUS";



	system("pause");

	return 0;
}