#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 301

int stair[MAX];
int D[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	D[1] = stair[1];
	D[2] = stair[1] + stair[2];
	D[3] = max(stair[1]+stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++) {
		D[i] = max((D[i - 3] + stair[i - 1] + stair[i]), (D[i - 2] + stair[i]));
	}

	cout << D[N];


	return 0;
}