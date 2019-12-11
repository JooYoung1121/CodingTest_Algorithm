#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int map[20][20];

int dx[4] = {-1,0,1,1}; // upright right downright down
int dy[4] = {1,1,1,0};


int main() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;
	int x, y;


	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 19; j++) {
			for (int m = 1; m <= 19; m++) {
				if (map[j][m] == 0)continue;
				int bx = j - dx[i];
				int by = m - dy[i];
				if (map[bx][by] == map[j][m])continue;
				int nx = j;
				int ny = m;
				int cnt = 1;
				while (1) {
					nx += dx[i];
					ny += dy[i];
					if (nx <= 0 || nx > 19 || ny <= 0 || ny > 19)break;

					if (map[nx][ny] != map[j][m]) break;

					cnt++;
				}

				if (cnt == 5)
				{
					x = j;
					y = m;
					result = map[x][y];
				}
			}
		}
	}

	cout << result << endl;
	if (result != 0)
		cout << x << ' ' << y << endl;


	system("pause");
	return 0;
}