#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

int map[11][11];
int cost[11][11];
bool visit[11][11] = {false,};
int N;

int result = 987654321;

int dx[5] = { 0,1,0,-1,0 };
int dy[5] = { -1,0,1,0,0 };

int cal_dist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool chk(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny]) return false;
	}
	return true;
}

void cost_cal(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		sum += map[nx][ny];
	}
	cost[x][y] = sum;
}


void dfs(int x,int y,int cnt,int val) {
	if (cnt == 3) {
		result = min(result, val);
	}
	else {
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			visit[nx][ny] = true;
		}

		for (int i = y + 3; i < N; i++) {
			if (chk(x, i))
				dfs(x, i, cnt + 1, val + cost[x][i]);
		}

		for (int i = 2; i < N; i++) {
			for (int j = 2; j < N; j++) {
				if (chk(i, j))
					dfs(i, j, cnt + 1, val + cost[i][j]);
			}
		}

		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			visit[nx][ny] = false;
		}

	}

}


int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			cost[i][j] = 0;
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			cost_cal(i, j);
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			dfs(i, j, 1, cost[i][j]);
		}
	}

	cout << result;

	system("pause");
	return 0;
}