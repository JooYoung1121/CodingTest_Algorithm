#include <iostream>
#include <Windows.h>

using namespace std;

char map[26][26];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y) {

}


int main() {
	int R, C;

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}



	return 0;
}