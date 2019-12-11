#include <iostream>
#include <vector>
#include <queue>
#include <Windows.h>
#include <math.h>
using namespace std;

#define MAX 102
#define DIST 50

int dist(pair<int,int> a,pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}


bool visit[MAX] = { false, };
vector<int> graph[MAX];


void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visit[next] == false)
			dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int t;

	cin >> t;

	int N;

	while (t--) {
		cin >> N;
		vector<pair<int, int>> beer;


		for (int i = 0; i < N+2; i++) {
			int bx, by;
			cin >> bx >> by;
			beer.push_back({ bx,by });
		}

		for (int i = 0; i < MAX; i++) {
			visit[i] = false;
		}

		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < N+2; i++) {
			for (int j = i+1; j < N+2; j++) {
				if (dist(beer[i], beer[j]) <= 1000) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		dfs(0);

		if (visit[N + 1])
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';



	}
	system("pause");
	return 0;
}