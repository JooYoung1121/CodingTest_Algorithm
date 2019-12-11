#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;


#define INF 987654321
const int MAX = 400;
const int MAX_V = 2 * (MAX + 1); // 최대 정점 개수
const int S = MAX_V - 2; // 소스 정점
const int E = MAX_V - 1; // 싱크 정점


int N, M;
int c[MAX_V][MAX_V] = { 0 }; // 각 간선 용량
int d[MAX_V][MAX_V] = { 0 }; // 각 간선 비용
int f[MAX_V][MAX_V] = { 0 }; // 유량
vector<int> adj[MAX_V]; // 리스트(그래프)

int main() {

	// 소스 정점 : 803 싱크 정점 : 804 직원 1~400 일 401~800

	cin >> N >> M;
	// S와 직원을 연결
	for (int i = 1; i <= N; i++)
	{
		c[S][i] = 1;
		d[S][i] = 0;
		d[i][S] = 0;

		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	// T와 일을 연결
	for (int i = 1; i <= M; i++)
	{
		c[i + MAX][E] = 1;
		d[i + MAX][E] = 0;
		d[E][i + MAX] = 0;

		adj[i + MAX].push_back(E);
		adj[E].push_back(i + MAX);
	}


	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int work, cost;
			cin >> work >> cost;
			adj[i].push_back(work + MAX);
			adj[work + MAX].push_back(i);

			d[i][work + MAX] = cost;
			d[work + MAX][i] = -cost;

			c[i][work + MAX] = 1;
		}
	}

	int result = 0;
	int total = 0;
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


		// 경로상의 모든 간선에 flow만큼의 유량을 흘림 이 문제에선 flow는 1 
		for (int i = E; i != S; i = prev[i]) {
			result += d[prev[i]][i]; // 총 비용이 각 간선 비용만큼 증가 
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		total++;
	}
	cout << total << endl << result;

	system("pause");
	return 0;
}