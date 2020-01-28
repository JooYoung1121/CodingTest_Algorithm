#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
typedef pair<int, int> p;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int map[MAX][MAX];

struct info {
	int x, y, cost;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.cost > b.cost)
			return true;
		return false;
	}
};


int main() {

	int M, N;

	cin >> M >> N;

	vector<p> fresh;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				fresh.push_back({i,j});
		}
	}

	priority_queue<info, vector<info>, cmp> pq;
	
	for (int i = 0; i < fresh.size(); i++) {
		p tmp = fresh[i];
		pq.push({ tmp.first,tmp.second,0 });
	}


	int result;
	while (!pq.empty()) {
		info tmp = pq.top();
		pq.pop();
		result = tmp.cost;
		for (int i = 0; i < 4; i++) {
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == -1 || map[nx][ny] == 1)continue;
			map[nx][ny] = 1;
			pq.push({ nx,ny,tmp.cost + 1 });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << result;

	system("pause");
	return 0;
}