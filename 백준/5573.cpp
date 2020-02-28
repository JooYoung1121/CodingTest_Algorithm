#include <iostream>
using namespace std;

#define MAX 1001

int road[MAX][MAX];
int D[MAX][MAX];

int main() {
	int H, W, N;

	cin >> H >> W >> N;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> road[i][j];
		}
	}
	

	D[1][1] = N - 1;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (D[i][j] == 0) continue;

			D[i + 1][j] += D[i][j] / 2;
			D[i][j + 1] += D[i][j] / 2;

			if (D[i][j] % 2 == 1) {
				if (road[i][j] == 1) D[i][j + 1]++;
				else D[i + 1][j]++;
			}

			road[i][j] = (road[i][j] + D[i][j]) % 2;
		}
	}

	int x=1, y=1;
	while (x <= H && y <= W) {
		if (road[x][y] == 1) y++;
		else x++;
	}

	cout << x << " " << y << endl;

	return 0;
}