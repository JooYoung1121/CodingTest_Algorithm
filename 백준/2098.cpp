#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 16
#define INF 987654321

int Arr[MAX][MAX];
int D[MAX][1<<MAX];

int N;

int solve(int start, int end) {

	if (end == (1<<N) -1) {
		if (Arr[start][0] != 0) {
			return Arr[start][0];
		}
		return INF;
	}

	int &sum = D[start][end];
	if (sum != -1) return sum;
	sum = INF;

	for (int next = 0; next < N; next++) {
		if (end & (1<<next) || Arr[start][next] == 0) // 이미 방문한 도시 
			continue;
		int ca = Arr[start][next] + solve(next, end + (1 << next));
		sum = min(sum, ca);
	}

	return sum;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Arr[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1<<MAX; j++) {
			D[i][j] = -1;
		}
	}
	int result;
	result = solve(0, 1);

	cout << result;
	return 0;
}