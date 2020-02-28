#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

vector<int> graph[MAX];

bool Cut[MAX] = {false,};
int isVisit[MAX];

int visit = 1;

int dfs(int start, bool Root) {
	
	isVisit[start] = visit++;

	int low = isVisit[start];

	int child = 0;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		
		if (isVisit[next] > 0) {
			low = min(low, isVisit[next]);
			continue;
		}

		child++;
		int pre = dfs(next, false);

		if (!Root && pre >= isVisit[start]) {
			Cut[start] = true;
		}

		low = min(low, pre);
	}

	if (Root) {
		Cut[start] = (child >= 2);
	}

	return low;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	int count = 0;

	

	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	for (int i = 1; i <= V; i++) {
		if(isVisit[i] == 0)
			dfs(i, true); // 임의의 root 값
	}

	for (int i = 1; i <= V; i++) {
		if (Cut[i])
			count++;
	}
	cout << count << "\n";

	for (int i = 1; i <= V; i++) {
		if (Cut[i])
			cout << i << " ";
	}
	cout << "\n";

	
	return 0;
}