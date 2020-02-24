#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 31

struct info {
	int x, y, h;
	int cost = 0;
};

int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };

char Building[MAX][MAX][MAX];

bool visit[MAX][MAX][MAX] = { false, };

info Start, End;

int main() {
	int L, R, C;

	while (1) {

		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			break;

		for (int h = 1; h <= L; h++) {
			for (int x = 1; x <= R; x++) {
				for (int y = 1; y <= C; y++) {
					cin >> Building[x][y][h];
					if (Building[x][y][h] == 'S')
						Start = { x,y,h };
					if (Building[x][y][h] == 'E')
						End = { x,y,h };
					visit[x][y][h] = false;
				}
			}
		}



		queue<info> q;

		q.push(Start);

		visit[Start.x][Start.y][Start.h] = true;

		int answer = 0;

		bool chk = false;

		while (!q.empty()) {
			info tmp;
			tmp = q.front();
			q.pop();

			int h = tmp.h;
			int x = tmp.x;
			int y = tmp.y;
			int cost = tmp.cost;

			if (x == End.x && y == End.y && h == End.h) {
				chk = true;
				answer = cost;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nh = h + dh[i];

				if (nx <= 0 || nx > R || ny <= 0 || ny > C || nh <= 0 || nh > L)continue;
				if (Building[nx][ny][nh] == '#')continue;
				if (visit[nx][ny][nh])continue;

				q.push({ nx,ny,nh,cost + 1 });
				visit[nx][ny][nh] = true;

			}
		}

		if (chk)
			cout << "Escaped in " << answer << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;

	}
	return 0;
}