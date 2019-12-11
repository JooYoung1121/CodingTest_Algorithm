#include <iostream>
#include <vector>
#include <queue>
#include <Windows.h>
using namespace std;

#define INF 1000000000

char map[50][50];
int dist[50][50];
int dx[4] = { -1,0,1,0 }; // 위 왼 아 오
int dy[4] = { 0,-1,0,1 };

int cost[100][100];
int A[100];
int B[100];
bool visited[100];

int limit;

int N, M;

bool dfs(int a) {
	visited[a] = true;
	for (int b = 0; b<M; b++) {
		if (cost[a][b] <= limit && (B[b] == -1 || !visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}


int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int R, C;

	cin >> R >> C;

	vector<pair<int, int>> car, park;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C')
				car.push_back({ i,j });
			else if (map[i][j] == 'P')
				park.push_back({ i,j });
		}
	}
	N = car.size();
	M = park.size();

	if (N > M) {
		cout << -1;
		return 0;
	}

	if (N == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int dist[50][50];
		bool visit[50][50] = { false, };

		int X, Y;
		X = car[i].first;
		Y = car[i].second;

		for (int k = 0; k < R; k++) {
			for (int m = 0; m < C; m++) {
				dist[k][m] = INF;
			}
		}

		queue<pair<int, int>> q;
		q.push({ X,Y });
		visit[X][Y] = true;
		dist[X][Y] = 0;

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			int cx, cy;
			cx = p.first;
			cy = p.second;

			for (int i = 0; i < 4; i++) {
				int nextX = cx + dx[i];
				int nextY = cy + dy[i];

				if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) continue;

				if (!visit[nextX][nextY] && map[nextX][nextY] != 'X') {
					visit[nextX][nextY] = true;
					dist[nextX][nextY] = dist[cx][cy] + 1;
					q.push({ nextX,nextY });
				}
			}
		} // BFS

		for (int j = 0; j < M; j++) {
			cost[i][j] = dist[park[j].first][park[j].second];
		}

	} // 그래프 만들기


	int match = 0;

	for (int i = 0; i < N; i++) {
		A[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		B[i] = -1;
	}

	limit = INF-1;

	for (int i = 0; i < N; i++) {
		if (A[i] == -1) {
			for (int j = 0; j < N; j++) {
				visited[j] = false;
			}
			if (dfs(i)) match++;
		}
	}

	if (match != N) {
		cout << -1;
		return 0;
	}

	int lo = 0, hi = R * C;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		limit = mid;
		match = 0;

		for (int i = 0; i < N; i++) {
			A[i] = -1;
		}
		for (int i = 0; i < M; i++) {
			B[i] = -1;
		}

		for (int i = 0; i < N; i++) {
			if (A[i] == -1) {
				for (int j = 0; j < N; j++) {
					visited[j] = false;
				}
				if (dfs(i)) match++;
			}
		}
		if (match == N) hi = mid;
		else lo = mid;
	}

	cout << hi;


	system("pause");
	return 0;
}