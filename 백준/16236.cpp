#include <iostream>
#include <Windows.h>
#include <queue>
using namespace std;

#define MAX 21
#define INF 10001

int map[MAX][MAX];
int D[MAX][MAX];

int N, min_d, min_x, min_y;
int shark_size = 2;
int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;

	D[x][y] = 0;

	q.push({ x,y });

	while (!q.empty()) {
		pair<int, int> cur;
		cur = q.front();
		q.pop();

		x = cur.first;
		y = cur.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (D[nx][ny] != -1 || map[nx][ny] > shark_size)
				continue;

			D[nx][ny] = D[x][y] + 1;

			if (map[nx][ny] != 0 && map[nx][ny] < shark_size) { // 먹을 수 있는 상어가 나타난다면
				if (min_d > D[nx][ny]) { // 가까운 상어가 나오면 업데이트 
					min_x = nx;
					min_y = ny;
					min_d = D[nx][ny];
				}
				else if (min_d == D[nx][ny]) { // 거리가 같은 상어 위치일 경우는 
					if (min_x == nx) {// 가장위부터
						if (min_y > ny) {
							min_x = nx;
							min_y = ny;
						}
					}
					else if (min_x > nx) { // 그다음 왼쪽 
						min_x = nx;
						min_y = ny;
					}
				}


			}
			q.push({nx,ny});
		}
	}
}

int main() {

	cin >> N;

	int sx, sy;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
		}
	}

	int result = 0;
	int cnt = 0;

	while (1) {

		min_d = INF;
		min_x = MAX;
		min_y = MAX;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = -1;
			}
		}

		bfs(sx, sy);

		if (min_x != MAX && min_y != MAX) {
			result += D[min_x][min_y];
			cnt++;
			if (cnt == shark_size) {
				cnt = 0;
				shark_size++;
			}

			map[min_x][min_y] = 0;

			sx = min_x;
			sy = min_y;
		}
		else
			break;

	}

	cout << result;

	system("pause");
	return 0;
}