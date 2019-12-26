#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;


	vector<int> info[20001];
	bool visit[20001] = { false, };
	vector<int> _min(n+1,0);


	for (int i = 0; i < edge.size(); i++) {
		info[edge[i][0]].push_back(edge[i][1]);
		info[edge[i][1]].push_back(edge[i][0]);
	}

		
	queue<pair<int,int>> q; // node , cnt
		
	visit[1] = true;
	for (int i = 0; i < info[1].size(); i++) {
		int nx = info[1][i];
		visit[nx] = true;
		q.push({ nx, 1 });
		_min[nx] = 1;
	}

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		int nx = tmp.first;
		int cnt = tmp.second;
		for (int i = 0; i < info[nx].size(); i++) {
			int nnx = info[nx][i];
			if (visit[nnx]) continue;

			visit[nnx] = true;
			_min[nnx] = cnt + 1;
			q.push({nnx,_min[nnx]});

		}
	}

	sort(_min.begin(), _min.end(), greater<int>());

	for (int i = 0; i < _min.size(); i++) {
		if (_min[0] == _min[i])
			answer++;
		else break;
	}

	return answer;
}

int main() {

	vector<vector<int>> edge;

	int N,M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		vector<int> temp;

		int a, b;
		cin >> a >> b;

		temp.push_back(a);
		temp.push_back(b);
		edge.push_back(temp);
	}

	cout << solution(N,edge);


	system("pause");
	return 0;
}