#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 201


vector<int> link[MAX];
bool visit[MAX] = {false,};
int result = 0;

void dfs(int node) {

	visit[node] = true;

	for (int i = 0; i < link[node].size(); i++) {
		int next = link[node][i];
		if (visit[next]) continue;
		dfs(next);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	

	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers[i].size(); j++) {
			if (computers[i][j]) {
				link[i].push_back(j);
				link[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (visit[i])
			continue;
		dfs(i);
		answer++;
	}

	return answer;
}

int main() {
	int N;

	cin >> N;
	vector<vector<int>> computers;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		computers.push_back(tmp);
	}

	cout << solution(N,computers);


	system("pause");
	return 0;
}