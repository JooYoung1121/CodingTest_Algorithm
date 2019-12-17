#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_K 1000000010

int D[202][202];

void solution(int n,int m,int k) {
	string result;
	
	while (!(n == 0 && m == 0)) {
		if (n == 0) {
			result += 'z';
			m--;
			continue;
		}
		if (m == 0) {
			result += 'a';
			n--;
			continue;
		}
		

		if (k <= D[n+m-1][n-1]) {
			result += 'a';
			n--;
		}
		else {
			result += 'z';
			k -= D[n+m-1][n-1];
			m--;
		}
	}
	cout << result << endl;

	

}

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i <= N+M; i++) {
		D[i][0] = 1;
		D[i][i] = 1;
		for (int j = 1; j < i; j++) {
			D[i][j] = min(MAX_K,D[i - 1][j-1] + D[i-1][j]);
		}
	}
	if (D[N+M][N] < K) {
		cout << -1 << endl;
	}
	else {
		solution(N, M, K);
	}

	return 0;
}