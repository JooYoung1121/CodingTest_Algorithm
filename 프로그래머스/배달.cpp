#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 51
#define INF 987654321
typedef pair<int, int> p;

int N,K,M;

vector<p> road2[MAX];

int k;
bool chk[MAX] = {false,};


bool visit[MAX] = {false,};
int res[MAX];

int solve(int node,int dist,int N,int K) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({dist,node});


	int idx = N;
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		if (visit[now.second]) continue;
		if (now.first > K)idx--;
		visit[now.second] = true;

		for (int i = 0; i < road2[now.second].size(); i++) {
			int next = road2[now.second][i].first;
			int cost = road2[now.second][i].second;

			if (!visit[next] && res[next] > now.first + cost) {
				res[next] = now.first + cost;
				pq.push({res[next],next});
			}
		}
	}
	return idx;
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i <= N; i++) {
		res[i] = INF;
	}

    for (int i = 0; i < road.size(); i++) {
       
		int a, b, c;
        a = road[i][0];
        b = road[i][1];
        c = road[i][2];
		road2[a].push_back({ b,c });
		road2[b].push_back({ a,c });   
	}
    
    res[1] = 0;
    answer = solve(1,0,N,K);
    return answer;
}