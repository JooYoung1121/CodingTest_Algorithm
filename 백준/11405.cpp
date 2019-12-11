#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;


#define INF 987654321
const int MAX = 100;
const int MAX_V = 2 * (MAX + 1); // 최대 정점 개수
const int S = MAX_V - 2; // 소스 정점
const int E = MAX_V - 1; // 싱크 정점


int N, M;
int c[MAX_V][MAX_V] = { 0 }; // 각 간선 용량
int d[MAX_V][MAX_V] = { 0 }; // 각 간선 비용
int f[MAX_V][MAX_V] = { 0 }; // 유량
vector<int> adj[MAX_V]; // 리스트(그래프)

int main() {

	cin >> N >> M;

	for (int i = MAX; i < MAX + N; i++) {
		cin >> c[i][E];
		adj[E].push_back(i);
		adj[i].push_back(E);
	}

	for (int i = 0; i < M; i++) {
		cin >> c[S][i];
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 0; i < M; i++) {
		for (int j = MAX; j < MAX + N; j++) {
			cin >> d[i][j];
			d[j][i] = -d[i][j];
			c[i][j] = INF;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	int result = 0;

	while (1) {
		int prev[MAX_V], dist[MAX_V];
		bool chk[MAX_V] = { false, }; // 해당 정점이 큐안에 있는지
		queue<int> q;

		memset(prev, -1, sizeof(prev));

		for (int i = 0; i < MAX_V; i++) {
			dist[i] = INF;
		}
		dist[S] = 0;
		chk[S] = true;
		q.push(S);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			chk[cur] = false;

			for (int next : adj[cur]) { // 최단 경로를 찾으면서 유량이 있어야함
				if (c[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					prev[next] = cur;
					if (!chk[next]) {
						q.push(next);
						chk[next] = true;
					}
				}
			}
		}

		if (prev[E] == -1)break; // 더이상 경로가 없으면 탈출

		int flow = INF;
		// 경로상에서 가장 residual이 작은 간선을 찾아 최대 흘릴 수 있는 flow찾음
		for (int i = E; i != S; i=prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		// 경로상의 모든 간선에 flow만큼의 유량을 흘림 
		for (int i = E; i != S; i = prev[i]) {
			result += flow * d[prev[i]][i]; // 총 비용이 각 간선 비용만큼 증가 
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

	}
	cout << result;

	system("pause");
	return 0;
}