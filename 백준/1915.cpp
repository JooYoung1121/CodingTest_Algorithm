#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int arr[MAX][MAX];
int D[MAX][MAX];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - 48;
			if (i == 1) {
				D[i][j] = arr[i][j];
			}
			if (j == 1) {
				D[i][j] = arr[i][j];
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] != 0) {
				D[i][j] = min(min(D[i][j - 1], D[i - 1][j]), D[i - 1][j - 1]) + 1;
			}
			result = max(D[i][j], result);
		}
	}

	cout << result*result;

	return 0;
}