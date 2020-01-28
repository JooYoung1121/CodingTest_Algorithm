#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
bool visit[26][26] = {false,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int cnt;

void dfs(int x, int y) {

	if (visit[x][y]) return;
	visit[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;

		if (map[nx][ny] == 1)
			dfs(nx, ny);
	}

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j] - '0';
		}
	}
	
	vector<int> result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (map[i][j] == 1 && !visit[i][j]) {
				dfs(i, j);
				result.push_back(cnt);
			}
		}
	}

	cout << result.size() << endl;

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}


	system("pause");
	return 0;
}