#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[50001];

queue<int> q;

bool check[50001] = {false,};

int parent[50001];
int depth[50001];

int lca(int f, int s) {

	if (depth[f] < depth[s])
		swap(f, s);
	while (depth[f] != depth[s])
	{
		f = parent[f];
	}
	while (f != s)
	{
		f = parent[f];
		s = parent[s];
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int _depth = 0;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int first, second;
		cin >> first >> second;
		a[first].push_back(second);
		a[second].push_back(first);
	}

	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			if (!check[a[x][i]]) {
				depth[a[x][i]] = depth[x] + 1;
				check[a[x][i]] = true;
				parent[a[x][i]] = x;
				q.push(a[x][i]);
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int first, second;
		cin >> first >> second;
		cout << lca(first, second) << '\n';
	}

	return 0;
}