#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool visit[300][300] = {false,};

vector<vector<int>> map;

int N, H,answer;

struct info {
	int x, y, cost;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.cost > b.cost) return true;
		return false;
	}
};

void dfs(int x, int y, priority_queue<info, vector<info>, cmp>& pq) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (visit[nx][ny]) continue;
		int cost = abs(map[nx][ny] - map[x][y]);
		if (cost > H) {
			pq.push({ nx, ny, cost });
			continue;
		}
		dfs(nx, ny, pq);
	}
}

void search(priority_queue<info, vector<info>, cmp>& pq) {
	if (pq.empty())return;
	int nx = pq.top().x;
	int ny = pq.top().y;
	int ncost = pq.top().cost;
	pq.pop();
	if (visit[nx][ny]) search(pq);
	else {
		answer += ncost;
		dfs(nx, ny, pq);
	}
}


int solution(vector<vector<int>> land, int height) {
	answer = 0;

	map = land;
	N = land.size();
	H = height;

	priority_queue<info,vector<info>,cmp> q;
	q.push({0,0,0});

	while (!q.empty()) {
		search(q);
	}

	return answer;
}


int main() {
	vector<vector<int>> land;
	int height;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		land.push_back(tmp);
	}

	cin >> height;

	cout << solution(land, height);


	system("pause");
	return 0;
}