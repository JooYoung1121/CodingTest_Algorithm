#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

vector<int> game[150];

bool visit[150] = { false, };

int cnt = 0;

int K;

void solve(int node) {
	visit[node] = true;

	if (node == K)
		return;

	int next = game[node][0];

	if (visit[next]) {
		return;
	}
	else {
		cnt++;
		solve(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N >> K;


	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		game[i].push_back(num);
	}

	solve(0);

	if (visit[K])
		cout << cnt;
	else
		cout << -1;


	system("pause");
	return 0;
}