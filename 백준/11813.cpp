/*#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
#define LL long long

#define MAX 100001

map<int, ll> mapp[MAX];
int N, u, v, w;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> conn;
int myXor[MAX];
*/


#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define LL long long
#define MAX 100001
typedef pair<int, int> P;

ll n, uf[MAX], sz[MAX], order[MAX];
vector<P> adj[MAX], edge;
vector<ll> answer;
map<ll, ll> mp[MAX]; //mp[u] : {1~v까지 xor한 값, 그 개수} //v는u집합요소

int find(int u) {
	if (uf[u] == -1) return u;
	return uf[u] = find(uf[u]);
}
ll merge(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] < sz[v]) swap(u, v);
	uf[v] = u;
	sz[u] += sz[v];
	sz[v] = 1;
	ll ret = answer.back();
	for (P p : mp[v]) {
		int x, cnt; tie(x, cnt) = p;
		ret += mp[v][x] * mp[u][x];
		mp[u][x] += mp[v][x];
	}
	return ret;
}
void dfs(int u, int p, int xr) {
	mp[u][xr] = 1;
	for (P next : adj[u]) if (next.first != p)
		dfs(next.first, u, xr ^ next.second);
}
void init() {
	memset(uf, -1, sizeof(uf));
	fill(sz, sz + n + 1, 1);
	answer.push_back(0);
}

int main() {
	cin >> n;
	init();
	for (int i = 0, u, v, w; i < n - 1; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
		edge.push_back({ u,v });
	}
	for (int i = 0; i < n - 1; i++) cin >> order[i];
	dfs(1, 0, 0);
	for (int i = n - 2, u, v; i >= 0; i--) {
		tie(u, v) = edge[order[i] - 1];
		answer.push_back(merge(u, v));
	}
	for (int i = n - 1; i >= 0; i--)
		cout << answer[i] << '\n';
}