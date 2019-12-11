#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 501
#define INF 987654321


int dist[MAX][MAX];
int visit[MAX][MAX];
int road[MAX][MAX];

int S, D;


int solve(int s, int d) {



	return 0;
}

int main() {
	int N, M;


	while (1) {

		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
				visit[i][j] = 0;	
			}
		}
		
		cin >> S >> D;

		for (int i = 0; i < M; i++) {
			int a, b, c;

			cin >> a >> b >> c;

			road[a][b] = c;
		}


		cout << solve(S, D) << "\n";

	}


	system("pause");
	return 0;
}