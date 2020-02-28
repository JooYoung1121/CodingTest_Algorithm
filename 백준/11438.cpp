#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 100001
#define Len 16

vector<int> a[MAX];

int p[MAX][Len+1]; // parent[V][K]

queue<int> q;

bool check[MAX] = { false, };

int depth[MAX];

int lca(int f, int s) {

	if (depth[f] < depth[s])
		swap(f, s);

	for (int i = Len; i >= 0; i--) {
		if (1 << i <= depth[f] - depth[s]) {
			f = p[f][i];
		}
	}
	if (f == s) {
		return f;
	}

	for (int i = Len; i >= 0; i--) {
		if (p[f][i] != p[s][i]) {
			f = p[f][i];
			s = p[s][i];
		}
	}
	return p[f][0];
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
				q.push(a[x][i]);
				p[a[x][i]][0] = x;
				for (int j = 1; j <= Len; j++) {
					p[a[x][i]][j] = p[p[a[x][i]][j - 1]][j - 1];
				}
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


