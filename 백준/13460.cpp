#include <iostream>
#include <Windows.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX 11

struct pos {
	int cnt;
	pair<int, int> r, b;
};

char map[MAX][MAX];
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
pair<int, int> red, blue, hole;
bool visit[MAX][MAX][MAX][MAX] = {false,};

int bfs() {
	queue<pos> q;
	q.push(pos{0,red,blue});

	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		if (p.cnt > 10) break;

		if (p.r == hole)
			return p.cnt;

		for (int i = 0; i < 4; i++) {
			pair<int, int> re, bl;
			re = p.r;
			bl = p.b;
			while (1) { //red
				int nx, ny;
				nx = re.first + dx[i];
				ny = re.second + dy[i];
				if (map[nx][ny] == '#')
					break;
				else if (map[nx][ny] == 'O') {
					re.first = nx;
					re.second = ny;
					break;
				}
				re.first = nx;
				re.second = ny;
			}
			while (1) { // blue
				int nx, ny;
				nx = bl.first + dx[i];
				ny = bl.second + dy[i];
				if (map[nx][ny] == '#')
					break;
				else if (map[nx][ny] == 'O') {
					bl.first = nx;
					bl.second = ny;
					break;
				}
				bl.first = nx;
				bl.second = ny;
			}
			if (bl == hole) continue;

			if (re == bl) {
				if (i == 0) { // up
					if (p.r.first < p.b.first)
						bl.first++;
					else
						re.first++;
				}
				else if (i == 1) { //right
					if (p.r.second < p.b.second)
						re.second--;
					else
						bl.second--;
				}
				else if (i == 2) { // down
					if (p.r.first < p.b.first)
						re.first--;
					else
						bl.first--;
				}
				else { // left
					if (p.r.second < p.b.second)
						bl.second++;
					else
						re.second++;
				}
			}

			if (!visit[re.first][re.second][bl.first][bl.second]) {
				q.push({ p.cnt + 1,re,bl });
				visit[re.first][re.second][bl.first][bl.second] = true;
			}

		}
	}

	return -1;
}


int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				red = { i,j };
			if (map[i][j] == 'B')
				blue = { i,j };
			if (map[i][j] == 'O')
				hole = { i,j };
		}
	}


	cout << bfs();



	system("pause");
	return 0;
}