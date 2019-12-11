#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 2001

char borad[MAX][MAX];
int D[MAX][MAX];

int dx[4] = {0,-1,0,1}; // 왼 위 오 아
int dy[4] = {-1,0,1,0};

// 완전탐색? 브루트포스? DP?

int solve(int a, int b) {
	
	
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	int N, M;

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> borad[i][j];
			D[i][j] = 1;
		}
	}

	

	if (solve(1, 1) == 0)
		cout << -1;
	else
	{
		cout << 1 << '\n';
	}

	system("pause");

	return 0;

}