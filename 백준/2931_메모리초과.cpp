#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
 // 메모리초과 문제
#define MAX 30
typedef pair<int, int> p;

char Gas[MAX][MAX];
bool visit[MAX][MAX] = { false, };

struct info {
	int x, y, dir;
};

int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };
char Pipe[7] = { '|', '-', '+', '1', '2', '3', '4' };

p start, ResultPos;
char Result;
vector<p> Pipe_pos;
bool Finish_Flag = false;

int R, C;

int Set_Direction(int dir, char G) {
	int Ndir = -1;
	if (G == '-') {
		if (dir == 1 || dir == 3) Ndir = dir;
	}
	else if (G == '|') {
		if (dir == 0 || dir == 2) Ndir = dir;
	}
	else if (G == '+') {
		Ndir = dir;
	}
	else if (G == '1') {
		if (dir == 0) Ndir = 1;
		else if (dir == 3) Ndir = 2;
	}
	else if (G == '2') {
		if (dir == 2) Ndir = 1;
		else if (dir == 3) Ndir = 0;
	}
	else if (G == '3') {
		if (dir == 1) Ndir = 0;
		else if (dir == 2)Ndir = 3;
	}
	else {
		if (dir == 0) Ndir = 3;
		else if (dir == 1) Ndir = 2;
	}
	return Ndir;
}

bool Finish_Check() {
	for (auto i : Pipe_pos) {
		int x = i.first;
		int y = i.second;

		if (!visit[x][y]) return false;
	}
	return true;
}

p bfs() {
	queue<info> q;
	info tmp = { start.first,start.second,0 }; // 일단 up먼저
	q.push(tmp);

	
	int nx, ny;

	while (!q.empty()) {
		if (Finish_Flag)break;
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		if (Gas[x][y] == 'M') {
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;

				if (Gas[nx][ny] == 'Z')continue;
				if (Gas[nx][ny] != '.') {
					dir = Set_Direction(i, Gas[nx][ny]);
					if (dir == -1)continue;
					q.push({ nx,ny,dir });
					visit[nx][ny] = true;
				}
			}

			if (q.size() == 0) { // 시작부터 갈 곳이 없을 경우 
				for (int i = 0; i < 4; i++) {
					memset(visit, false, sizeof(visit));
					if (Finish_Flag) break;
					nx = x + dx[i];
					ny = y + dy[i];

					if (nx <= 0 || nx > R || ny <= 0 || ny > C) continue;

					for (int pipe = 0; pipe < 7; pipe++) {
						memset(visit, false, sizeof(visit));
						Gas[nx][ny] = Pipe[pipe];
						p Tmp;
						Tmp = bfs();
						if (Tmp.first == -1 && Tmp.second == -1) {
							if (Finish_Check()) {
								Finish_Flag = true;
								cout << x << ' ' << y << ' ' << Pipe[pipe];
								system("pause");
								return { x,y };
							}
						}
						Gas[nx][ny] = '.';
					}

				}
			}
		}
		else {
			nx = x + dx[dir];
			ny = y + dy[dir];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;

			if (Gas[nx][ny] == '.') return { nx,ny };
			if (Gas[nx][ny] == 'Z') return { -1,-1 };

			dir = Set_Direction(dir, Gas[nx][ny]);
			if (dir == -1) return { nx,ny };
			visit[nx][ny] = true;
			q.push({ nx,ny,dir });
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> Gas[i][j];

			if (Gas[i][j] == 'M') {
				start = { i,j };
			}
			if (Gas[i][j] != 'M' && Gas[i][j] != 'Z' && Gas[i][j] != '.')
				Pipe_pos.push_back({ i,j });
		}
	}

	p Before, After;
	Before = bfs();
	int x = Before.first;
	int y = Before.second;

	if (Finish_Flag) return 0;

	for (int i = 0; i < 7; i++) {
		Gas[x][y] = Pipe[i];
		memset(visit, false, sizeof(visit));
		After = bfs();
		if (Finish_Flag) return 0;
		if (After.first == -1 && After.second == -1) {
			if (Finish_Check()) {
				cout << x << ' ' << y << ' ' << Pipe[i];
				system("pause");
				return 0;
			}
		}
	}

	system("pause");
	return 0;
}