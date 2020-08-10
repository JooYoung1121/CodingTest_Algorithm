#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, L, R, Answer = 0;

int Map[51][51];

bool Visit[51][51] = {false,};
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};

bool bfs(int x,int y) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	Visit[x][y] = true;
	vector<pair<int, int>> Union;
	Union.push_back({ x,y });
	int cnt = 0;
	int Sum = 0;

	while (!q.empty()) {
		pair<int, int> tmp;
		tmp = q.front();
		int Curx = tmp.first;
		int Cury = tmp.second;
		int Cur_People = Map[Curx][Cury];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = Curx + dx[i];
			int ny = Cury + dy[i];

			if (nx <= 0 || nx > N || ny <= 0 || ny > N)continue;
			if (Visit[nx][ny])continue;
			int Next_People = Map[nx][ny];
			int dist = abs(Cur_People - Next_People);
			if (dist < L || dist > R) continue;
			Visit[nx][ny] = true;
			q.push({ nx,ny });
			Union.push_back({ nx,ny });
		}
		cnt++;
		Sum += Map[Curx][Cury];
	}

	if (cnt == 1) return false;
	else {
		int Avg = Sum / cnt;

		for (auto U : Union) {
			Map[U.first][U.second] = Avg;
		}
		return true;
	}

}

void solve() {

	while (1) {
		bool flag = false;
		memset(Visit, false, sizeof(Visit));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!Visit[i][j]) {
					if (bfs(i, j)) {
						flag = true;
					}
				}
			}
		}
		if (!flag)
			break;
		else
			Answer++;
	}
}

int main() {
	
	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
		}
	}

	solve();

	cout << Answer;

	system("pause");
	return 0;
}