#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

vector<int> com[MAX];
bool visit[MAX];
int hack[MAX];

void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < com[node].size(); i++) {
		int next = com[node][i];
		if (!visit[next]) {
			hack[next]++;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		com[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		hack[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[j] = false;
		}
		dfs(i);
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		result = max(result, hack[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (result == hack[i])
			cout << i << ' ';
	}

	system("pause");
	return 0;
}