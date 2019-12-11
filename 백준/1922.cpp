#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int from, to, val;
};

int parent[1001];
vector<info> graph;
bool chk;

bool cmp(info a, info b) {
	return a.val < b.val;
}

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);

}

void merge(int from, int to) {

	chk = false;
	from = find(from);
	to = find(to);

	if (from == to)
		return;

	parent[from] = to;
	chk = true;

}

int main() {
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		info tmp;
		cin >> tmp.from >> tmp.to >> tmp.val;
		graph.push_back(tmp);
	}

	sort(graph.begin(), graph.end(), cmp);

	int result = 0;
	for (int i = 0; i < M; i++) {
		merge(graph[i].from, graph[i].to);

		if (chk)
			result += graph[i].val;
	}

	cout << result;

	system("pause");
	return 0;
}
 