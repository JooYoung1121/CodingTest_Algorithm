#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 51

int shark[MAX][3];

vector<int> hunt[MAX];
bool visit[MAX];
int check[MAX];

int N;

bool dfs(int x) {

	if (visit[x]) return false;
	visit[x] = true;
	for (int i = 0; i < hunt[x].size(); i++) {
		int next = hunt[x][i];

		if (check[next] == 0 || dfs(check[next]))
		{
			check[next] = x;
			return true;
		}


	}

	return false;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> shark[i][0];
		cin >> shark[i][1];
		cin >> shark[i][2];
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {

			if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2])
				hunt[i].push_back(j);
			else if(shark[i][0] <= shark[j][0] && shark[i][1] <= shark[j][1] && shark[i][2] <= shark[j][2])
				hunt[j].push_back(i);

		}
	}

	int cnt = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				visit[k] = false;
			}
			if (dfs(j)) cnt++;
		}
	}

	cout << N - cnt;

	system("pause");
	return 0;
}