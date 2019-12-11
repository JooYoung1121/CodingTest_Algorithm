#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 101

bool visit[MAX][MAX] = {false,};
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
int map[MAX][MAX];


int result = -1;

int N, M;

void solve(int x,int y,int cnt) { // dfs
	
	if (x == N && y == M) {
		if (result == -1) {
			result = cnt;
		}
		else {
			result = min(result, cnt);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny] || nx <= 0 || nx > N || ny <= 0 || ny > M)continue;
		if (map[nx][ny] == 0) continue;

		visit[nx][ny] = true;
		solve(nx, ny, cnt + 1);
		visit[nx][ny] = false;
	}

}

struct node{
	int x, y, cost;
};

int solution(vector<vector<int> > maps)
{
	int answer = -1;

	//int N = maps.size();
	//int M = maps[0].size();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = maps[i - 1][j - 1];
		}
	}


	queue<node> q;
	q.push({0,0,1});

	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.x == N - 1 && cur.y == M - 1) {
			answer = cur.cost;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (visit[nx][ny] || nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (maps[nx][ny] == 0) continue;
			visit[nx][ny] = true;
			q.push({nx,ny,cur.cost+1});
		}
	}
	
	//visit[1][1] = true;
	//solve(1, 1, 1);


	//answer = result;


	return answer;
}


int main() {
	
	vector<vector<int>> maps;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		maps.push_back(tmp);
	}

	cout << solution(maps);

	system("pause");
	return 0;
}