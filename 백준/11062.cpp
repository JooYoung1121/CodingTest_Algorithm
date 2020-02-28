#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int card[MAX];
int D[MAX][MAX][2];


int solve(int start, int end, int p) {
	int &sum = D[start][end][p];
	if (sum != -1) return sum;

	if (start >= end) {
		if (p == 0) return sum = card[start];
		else return sum = 0;
	}

	if (p == 0) {
		return sum = max(solve(start + 1, end, 1) + card[start], solve(start, end - 1, 1) + card[end]);
	}
	else {
		return sum = min(solve(start + 1, end, 0), solve(start, end - 1, 0));
	}


}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;

	cin >> T;


	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j][0] = -1;
				D[i][j][1] = -1;
			}
		}

		for (int j = 1; j <= N; j++) {
			cin >> card[j];
		}

		int count = 0;
		int start = 1;
		int end = N;

		int result;

		result = solve(start, end, 0);

		cout << result << "\n";

	}
	return 0;
}