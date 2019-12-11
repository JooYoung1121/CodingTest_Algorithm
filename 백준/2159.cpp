#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <Windows.h>
using namespace std;

#define MAX 100001

long long D[MAX][5]; // current 0 right 1 up 2 left 3 down 4 

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };


int main() {
	int N;

	cin >> N;

	int cx, cy;

	cin >> cx >> cy;

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < 5; i++) {
		long long _min = 987654321;
		for (int j = 0; j < 5; j++) {
			long long di = abs(x + dx[i] - cx) + abs(y + dy[i] - cy);
			_min = min(_min, di);
		}
		D[1][i] = _min;
	}

	cx = x;
	cy = y;


	for (int i = 2; i <= N; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < 5; j++) {
			long long _min = 10000000001;
			for (int k = 0; k < 5; k++) {
				long long di = D[i-1][k] + abs(x + dx[j] - (cx + dx[k]))
					+ abs(y + dy[j] - (cy + dy[k]));
				
				_min = min(_min, di);
			}
			D[i][j] = _min;
		}
		cx = x;
		cy = y;
	}

	long long _min = 10000000001;
	for (int i = 0; i < 5; i++) {
		_min = min(D[N][i], _min);
	}

	cout << _min;

	system("pause");
	return 0;
}