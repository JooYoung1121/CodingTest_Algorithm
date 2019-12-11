#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 21
#define INF 987654321

int map[MAX][MAX];
int visit[MAX][MAX];

int result = 0;
int N;


void solve() {

	//i->k k->j
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || j == k || k == i)
					continue;
				else if (map[i][j] > map[i][k] + map[k][j])
				{
					result = -1;
					return;
				}
				else if(map[i][j] == map[i][k] + map[k][j]) {
					visit[i][j] = 1;
				}

			}
		}
	}
}

int main() {
	

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	solve();


	if (result != -1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] == 0)
					result += map[i][j];
			}
		}
	}

	if (result == -1)
		cout << result;
	else
		cout << result / 2;


	system("pause");
	return 0;
}