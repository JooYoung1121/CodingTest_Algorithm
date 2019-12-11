#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

#define MAX 1001

int box[MAX];
int D[MAX];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> box[i];
		D[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (box[i] > box[j] && D[j] + 1 > D[i]) {
				D[i] = D[j] + 1;
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		if (max < D[i])
			max = D[i];
	}

	cout << max;

	system("pause");
	return 0;
}