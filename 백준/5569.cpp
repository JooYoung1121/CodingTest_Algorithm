#include <iostream>
#include <Windows.h>
using namespace std;

#define DIV 100000

int D[2][2][101][101];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int W, H;
	cin >> W >> H;

	for (int r = 1; r <= H; r++) D[0][0][r][1] = 1;
	for (int c = 1; c <= W; c++) D[1][0][1][c] = 1;
	for (int r = 2; r <= H; r++)
	{
		for (int c = 2; c <= W; c++)
		{
			D[0][0][r][c] += D[0][0][r - 1][c];
			if (r - 2 > 0) D[0][0][r][c] += (D[1][0][r - 2][c]);
			D[0][1][r][c] += D[1][0][r - 1][c];

			D[1][0][r][c] += D[1][0][r][c - 1];
			if (c - 2 > 0) D[1][0][r][c] += (D[0][0][r][c - 2]);
			D[1][1][r][c] += D[0][0][r][c - 1];

			D[0][0][r][c] %= DIV;
			D[1][0][r][c] %= DIV;
			D[0][1][r][c] %= DIV;
			D[1][1][r][c] %= DIV;
		}
	}

	int ans = (D[0][0][H][W] + D[1][0][H][W] + D[0][1][H][W] + D[1][1][H][W]) % DIV;

	cout << ans;

	system("pause");
	return 0;
}