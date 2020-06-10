#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 51

typedef pair<int, int> p;

int R, C, T; 
p Air[2]; // 공기청정기 위치

int map[MAX][MAX]; // 먼지 맵
int tmp[MAX][MAX];


int dx[4] = {-1,0,1,0}; // Up Right Down Left
int dy[4] = {0,1,0,-1};

void Copy_map() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

void Copy_tmp() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}

void diffusion() { // 미세먼지 확산 -> 동시에 확산!!!!!!!!!!

	int ttmp[MAX][MAX] = {0,};

	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			if (map[x][y] == -1) continue;
			if (map[x][y] != 0) {
				int div_dust = map[x][y] / 5; // 확산될 먼지 양
				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;
				 	if ((nx == Air[0].first && ny == Air[0].second) || (nx == Air[1].first && ny == Air[1].second)) continue;
					ttmp[nx][ny] += div_dust;
					//map[nx][ny] += div_dust;
					cnt++;
				}
				ttmp[x][y] -= (div_dust * cnt);
				//map[x][y] -= (div_dust * cnt);
			}
		}
	}

	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			if (map[x][y] == -1)continue;
			map[x][y] += ttmp[x][y];
		}
	}

}

void Move_wind(int x,int y,int air_num) {
	int dir = 1;
	int cur_x = x;
	int cur_y = y;

	if (air_num == 0) {
		while (1) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (ny > C) {
				dir = 0;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			else if (nx <= 0) {
				dir = 3;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			else if (ny <= 0) {
				dir = 2;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			if (nx == cur_x && ny == cur_y)break;
			if (map[x][y] == -1)
				tmp[nx][ny] = 0;
			else
				tmp[nx][ny] = map[x][y];
			x = nx;
			y = ny;
		}
	}
	else {
		while (1) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (ny > C) {
				dir = 2;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			else if (nx > R) {
				dir = 3;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			else if (ny <= 0) {
				dir = 0;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}

			if (nx == cur_x && ny == cur_y)break;
			if (map[x][y] == -1)
				tmp[nx][ny] = 0;
			else
				tmp[nx][ny] = map[x][y];
			x = nx;
			y = ny;
		}
	}
}

void Wind() { // 공기청정기 이동
	for (int i = 0; i < 2; i++) {
		Move_wind(Air[i].first, Air[i].second, i);
	}
	Copy_map();
}

int Sum() {
	int result = 0;
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			if(map[x][y] != -1)
				result += map[x][y];
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> R >> C >> T;

	int idx = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			tmp[i][j] = map[i][j];
			if (map[i][j] == -1)
				Air[idx++] = { i,j };
		}
	}

	while (T--) {
		diffusion();
		Copy_tmp();
		Wind();
	}

	cout << Sum();


	system("pause");
	return 0;
}