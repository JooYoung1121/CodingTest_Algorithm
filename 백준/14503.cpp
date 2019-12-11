#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 51

int map[MAX][MAX];

int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };

bool visit[MAX][MAX] = { false, };

int main() {
	int N, M;

	cin >> N >> M;
	int sx, sy;
	int dir;

	cin >> sx >> sy >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}



	int result = 1;

	map[sx][sy] = 2;

	int cnt = 0;
	while (1) {
		dir = (dir - 1 + 4) % 4; // 왼쪽 방향 바라보고

		int nx = sx + dx[dir];
		int ny = sy + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			cnt++;
			continue;
		}


		if (map[nx][ny] == 1 || map[nx][ny] == 2)
			cnt++;
		else {
			map[nx][ny] = 2;
			cnt = 0;
			sx = nx;
			sy = ny;
			result++;
		}

		if (cnt == 4) {
			int tmp = (dir - 1 + 4) % 4;
			tmp = (tmp - 1 + 4) % 4;

			nx = sx + dx[tmp];
			ny = sy + dy[tmp];

			if (map[nx][ny] == 1)
				break;
			else {
				cnt = 0;
				sx = nx;
				sy = ny;
			}
		}
	}


	cout << result;

	system("pause");
	return 0;
}