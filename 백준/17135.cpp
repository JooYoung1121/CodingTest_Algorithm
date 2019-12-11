#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 16

int N, M, D;

int map[MAX][MAX];
int tmp[MAX][MAX];
int war[3];
int ans;

int dx[3] = {0,-1,0}; // left up right
int dy[3] = {-1,0,1};

struct Node {
	int x, y, dist;
};

Node bfs(int x,int y) {
	bool visit[MAX][MAX] = {false,};
	queue<Node> q;
	q.push({x,y,1});
	visit[x][y] = true;

	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		if (tmp[node.x][node.y]) return node;

		for (int i = 0; i < 3; i++) {
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (node.dist + 1 > D || visit[nx][ny]) continue;

			q.push({nx,ny,node.dist+1});
			visit[nx][ny] = true;
		}
	}

	return { -1,-1,-1 };
}

void attack() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		vector<pair<int, int>> enemy;
		for (int j = 0; j < 3; j++) {
			Node node = bfs(i,war[j]);
			if (node.dist == -1)continue;
			enemy.push_back({node.x, node.y});
		}

		for (int m = 0; m < enemy.size(); m++) {
			int x = enemy[m].first;
			int y = enemy[m].second;

			if (tmp[x][y] == 0) continue;
			tmp[x][y] = 0;
			ret++;
		}
	}

	ans = max(ans, ret);
}

void dfs(int cnt,int idx) {
	if (idx > M) return;
	if (cnt == 3) {
		attack();
		return;
	}

	if (idx < M) {
		war[cnt] = idx;
		dfs(cnt + 1, idx + 1);
	}
	dfs(cnt, idx + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	ans = 0;

	dfs(0, 0); // 배치 명수 , 인덱스

	cout << ans;

	system("pause");
	return 0;
}