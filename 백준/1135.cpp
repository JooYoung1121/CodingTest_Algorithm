#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 51

vector<int> com[MAX];
priority_queue<pair<int,int>> pq[MAX];


int dfs(int node) {
	int ret = 0;

	for (int next : com[node]) {
		pq[node].push({ 1 + dfs(next),next });
	}

	int time = 0;

	while (!pq[node].empty()) {
		int cost = pq[node].top().first;
		pq[node].pop();
		ret = max(ret, cost + time);
		time++;
	}
	return ret;
}


int main() {
	int N;

	cin >> N;

	int tmp;
	cin >> tmp;

	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		com[a].push_back(i);
	}

	cout << dfs(0);


	system("pause");
	return 0;
}