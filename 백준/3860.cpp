#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int dx[4] = {0,-1,0,1}; // ¿Þ,À§,¿À,¾Æ
int dy[4] = {-1,0,1,0};

int map[30][30];
int D[30][30];


struct info {
	int x1, x2, y1, y2,T;
};

vector<info> ghost;

int solve(int x,int y) {




	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int W, H;

	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				map[i][j] = 0;
			}
		}
		int G;
		cin >> G;

		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> x >> y;

			map[y][x] = -1;
		}
		int E;
		cin >> E;

		ghost.clear();

		for (int i = 0; i < E; i++) {
			int x1, x2, y1, y2, T;
			cin >> x1 >> x2 >> y1 >> y2 >>T;
			info tmp;
			tmp.x1 = x1;
			tmp.x2 = x2;
			tmp.y1 = y1;
			tmp.y2 = y2;
			tmp.T = T;
			ghost.push_back(tmp);
		}

	}


	system("pause");
	return 0;
}