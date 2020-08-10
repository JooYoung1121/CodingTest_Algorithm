#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

char map[8][8];
char tmp[8][8];

int dx[9] = {-1,-1,-1,0,1,1,1,0,0};
int dy[9] = {-1,0,1,1,1,0,-1,-1,0};
int high = 0;

void move_map() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			tmp[j + 1][i] = map[j][i];
		}
		tmp[0][i] = '.';
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

bool solve() {
	queue<pair<int, int>> q;
	q.push({ 7,0 }); // x y

	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			if (map[x][y] == '#') continue;
			if (x <= high) return true;
			if (x == 0 && y == 7)return true;

			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
				if (map[nx][ny] == '#') continue;
				q.push({ nx,ny });
			}
		}
		move_map();
		high++;
	}


	return false;
}

int main() {

	bool chk = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#' && chk) {
				high = i;
				chk = false;
			}
		}
	}

	cout << solve();
	


	system("pause");
	return 0;
}