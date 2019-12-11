#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 501

char map[MAX][MAX];
int R, C;
vector<pair<int, int>> sheep;
vector<pair<int, int>> wolf;
int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S')
				sheep.push_back({ i,j });
		}
	}

	bool chk = true;

	for (int i = 0; i < sheep.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int nx = sheep[i].first + dx[j];
			int ny = sheep[i].second + dy[j];

			if (nx < 1 || nx > R || ny < 1 || ny > C)continue;

			if (map[nx][ny] == 'W') {
				chk = false;
				break;
			}
		}
		if (!chk)
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1 << "\n";

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == '.')
				cout << 'D';
			else
				cout << map[i][j];
		}
		cout << "\n";
	}


	system("pause");
	return 0;
}