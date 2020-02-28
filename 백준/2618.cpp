#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;

#define MAX 1001

pair<int, int> fir[MAX];
pair<int, int> sec[MAX];


int D[MAX][MAX]; // 경찰차 이 마지막으로 처리한 사건이 X이고 2가 마지막 처리하 사건이 Y

int W;

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int X, int Y) {
	if (X == W || Y == W) {
		return 0;
	}

	int &sum = D[X][Y];

	if (sum != -1) {
		return sum;
	}

	int next = max(X, Y) + 1;
	
	sum = min((solve(next, Y) + dist(fir[X], fir[next])), (solve(X, next) + dist(sec[Y], sec[next])));

	return sum;
}

vector<int> pos;
void track(int X, int Y) {
	if (X == W || Y == W) {
		return;
	}
	int next = max(X, Y) + 1;

	if ((D[next][Y] + dist(fir[X], fir[next])) > (D[X][next] + dist(sec[Y], sec[next]))) {
		pos.push_back(2);
		track(X, next);
	}
	else {
		pos.push_back(1);
		track(next, Y);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;

	cin >> N >> W;

	fir[0] = { 1,1 };
	sec[0] = { N,N };

	for (int i = 1; i <= W; i++) {
		cin >> fir[i].first;
		cin >> fir[i].second;
		sec[i] = { fir[i].first, fir[i].second };
	}
	// 사건의 순서는 road에 인덱스

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			D[i][j] = -1;
		}
	}

	cout << solve(0, 0) <<"\n";
	track(0, 0);

	for (auto a : pos)
		cout << a << "\n";

	return 0;

}