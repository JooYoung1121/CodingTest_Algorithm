#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 501
int D[MAX][MAX];

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> D[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		int temp;
		int _max;
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				D[i][j] += D[i - 1][j];
			else {
				D[i][j] += max(D[i - 1][j], D[i - 1][j - 1]);
			}
		}
	}
	int _max = D[1][1];
	for (int i = 1; i <= N; i++) {
		_max = max(_max, D[N][i]);
	}

	cout << _max << endl;


	return 0;
}