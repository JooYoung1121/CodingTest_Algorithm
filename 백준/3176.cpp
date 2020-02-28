#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#define MAX 100001
#define Len 20

typedef pair<int, int> pa;

vector<pa> a[MAX];

int p[MAX][Len + 1]; // parent[V][K]
int mn[MAX][Len + 1];
int mx[MAX][Len + 1];

queue<int> q;

bool check[MAX] = { false, };

int depth[MAX];

pa lca(int f, int s) {

	int _min = 987654321;
	int _max = -1;

	if (depth[f] < depth[s])
		swap(f, s);

	for (int i = Len; i >= 0; i--) {
		if (1 << i <= depth[f] - depth[s]) {
			_min = min(_min, mn[f][i]);
			_max = max(_max, mx[f][i]);
			f = p[f][i];
		}
	}
	if (f == s) {
		return {_min,_max};
	}

	for (int i = Len; i >= 0; i--) {
		if (p[f][i] != p[s][i]) {
			_min = min({ _min,mn[f][i],mn[s][i] });
			_max = max({ _max,mx[f][i],mx[s][i] });
			f = p[f][i];
			s = p[s][i];
		}
	}
	_min = min({ _min,mn[f][0],mn[s][0] });
	_max = max({ _max,mx[f][0],mx[s][0] });

	return { _min,_max };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int _depth = 0;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A,B,C;
		cin >> A >> B >> C;
		a[A].push_back({ B,C });
		a[B].push_back({ A,C });
	}

	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			if (!check[a[x][i].first]) {
				depth[a[x][i].first] = depth[x] + 1;
				mn[a[x][i].first][0] = mx[a[x][i].first][0] = a[x][i].second;
				check[a[x][i].first] = true;
				q.push(a[x][i].first);
				p[a[x][i].first][0] = x;
				for (int j = 1; j <= Len; j++) {
					p[a[x][i].first][j] = p[p[a[x][i].first][j - 1]][j - 1];
				}
			}
		}
	}

	for (int j = 1; j < Len + 1; j++) {
		for (int i = 1; i <= N; i++) {
			mn[i][j] = min(mn[i][j - 1], mn[p[i][j - 1]][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[p[i][j - 1]][j - 1]);
		}
	}
		

	cin >> K;
	for (int i = 0; i < K; i++) {
		int D,E;
		cin >> D >> E;
		pa t = lca(D, E);
		cout << t.first << " " << t.second << '\n';
	}

	return 0;
}


