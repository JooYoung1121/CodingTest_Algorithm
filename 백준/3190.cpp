#include <iostream>
#include <Windows.h>
#include <deque>
using namespace std;

#define MAX 101

int map[MAX][MAX];
pair<int, char> change[MAX]; // √ , πÊ«‚
int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };
bool visit[MAX][MAX] = {false,};
deque<pair<int, int>> q;

int main() {
	int N;

	cin >> N;

	int K;

	cin >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++) {
		int x, y;

		cin >> x >> y;

		map[x][y] = 1;
	}
	int L;

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> change[i].first >> change[i].second; 
	}

	q.push_back({1,1});

	int dir = 1; // 0 up 1 right 2 down 3 left

	int pos = 0;
	int result = 0;

	while (!q.empty()) {
		result++;

		pair<int, int> tmp;
		tmp = q.back();

		int nx = tmp.first + dx[dir];
		int ny = tmp.second + dy[dir];

		if (visit[nx][ny] || nx < 1 || nx > N || ny < 1 || ny > N)
			break;

		q.push_back({ nx,ny });

		visit[nx][ny] = true;

		if (map[nx][ny] == 1)
			map[nx][ny] = 0;
		else {
			tmp = q.front();
			visit[tmp.first][tmp.second] = false;
			q.pop_front();
		}


		
		if (pos < L && result == change[pos].first) {
			if (change[pos++].second == 'D')
				dir = (dir + 1 + 4) % 4;
			else
				dir = (dir - 1 + 4) % 4;
		}

	}

	cout << result;

	system("pause");
	return 0;
}