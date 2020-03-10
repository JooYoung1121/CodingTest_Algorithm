#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX 30
typedef pair<int, int> p;

char Gas[MAX][MAX];
bool visit[MAX][MAX] = { false, };

int dx[4] = { -1,1,0,0 }; // up down left right
int dy[4] = { 0,0,-1,1 };
char Pipe[7] = { '|', '-', '+', '1', '2', '3', '4' };
char tileList[4][5] =
{
	{ '|', '+', '1', '4', 'Z' }, // Up
	{ '|', '+', '2', '3', 'Z' }, // Down
	{ '-', '+', '1', '2', 'Z' }, // Left
	{ '-', '+', '3', '4', 'Z' }, // Right
};

bool Finish_Flag = false;

p start, ResultPos;
char Result;
int nTotal = 1;

int R, C;

void dfs(int x,int y,int dir,bool flag,int iTotal) {
	if (!visit[x][y]) {
		visit[x][y] = true;
		iTotal++;
	}

	if (Gas[x][y] == '1')
		dir = (dir + 3) % 4;
	else if (Gas[x][y] == '2' || Gas[x][y] == '4')
		dir = (dir + 2) % 4;
	else if (Gas[x][y] == '3')
		dir = (dir + 1) % 4;
	else if (Gas[x][y] == 'Z' && nTotal == iTotal) {
		Finish_Flag = true;
		return;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx <= 0 || nx > R || ny <= 0 || ny > C)return;

	if (Gas[nx][ny] != '.') {
		bool bTmp = false;
		for (int i = 0; i < 5; ++i)
		{
			if (tileList[dir][i] == Gas[nx][ny])
			{
				bTmp = true;
				break;
			}
		}
		if (!bTmp) return;

		dfs(nx, ny, dir, flag, iTotal);
		visit[nx][ny] = false;
	}

	if (Gas[nx][ny] == '.' && !flag) {
		for (int i = 0; i < 4; i++) {
			Gas[nx][ny] = tileList[dir][i];
			dfs(nx, ny, dir, true, iTotal);
			if (Finish_Flag) {
				ResultPos.first = nx;
				ResultPos.second = ny;
				Result = Gas[nx][ny];
				return;
			}
			visit[nx][ny] = false;
			Gas[nx][ny] = '.';
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

			if (Gas[i][j] == 'M') 
				start = { i,j };

			if (Gas[i][j] != '.') nTotal++;

		}
	}

	for (int i = 0; i < 4; i++) {
		dfs(start.first, start.second, i, false, 0);
		if (Finish_Flag) break;
		memset(visit, false, sizeof(visit));
	}

	cout << ResultPos.first << ' ' << ResultPos.second << ' ' << Result;


	system("pause");
	return 0;
}
