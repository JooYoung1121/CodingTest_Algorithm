#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 1001

int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };

char map[MAX][MAX];
int W, H;
vector<pair<int, int>> fire;

bool visit[MAX][MAX];

int solve(pair<int, int> s) {
	queue<pair<int, int>> q;
	q.push(s);
	queue<pair<int, int>> flame;
	int result = 0;


	for (int i = 0; i < fire.size(); i++) {
		flame.push(fire[i]);
	}

	while (!q.empty()) {
		int size = flame.size();

		for (int i = 0; i < size; i++) {
			int x, y;
			x = flame.front().first;
			y = flame.front().second;
			flame.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 1 && ny >= 1 && nx <= H && ny <= W) {
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						flame.push({ nx,ny });
					}
				}
			}
		}

		int cur = q.size();

		for (int i = 0; i < cur; i++) {
			int x, y;
			x = q.front().first;
			y = q.front().second;
			q.pop();

			if (x == 1 || y == 1 || x == H || y == W) {
				result++;
				return result;
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 1 && ny >= 1 && nx <= H && ny <= W) {
					if (map[nx][ny] != '#' && map[nx][ny] != '*' && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		result++;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;

	cin >> N;

	for (int m = 0; m < N; m++) {

		cin >> W >> H;

		pair<int, int> start;
		fire.clear();
		memset(visit, false, sizeof(visit));

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@')
					start = { i,j };
				if (map[i][j] == '*')
					fire.push_back({ i,j });
			}
		}

		int result = solve(start);

		if (result != -1) {
			cout << result << "\n";
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
		}

	}

	system("pause");
	return 0;
}