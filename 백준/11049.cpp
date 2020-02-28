#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 501

int arr[MAX][2];
int D[MAX][MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
	for (int l = 1; l <= N; l++) {
		for (int i = 1; i <= N - l;i++) {
			int j = i + l;
			D[i][j] = numeric_limits<int>::max();
			for (int k = i; k <= j; k++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k + 1][j] + (arr[i][0] * arr[k][1] * arr[j][1]));
			}
		}
	}


	cout << D[1][N];

	return 0;
}