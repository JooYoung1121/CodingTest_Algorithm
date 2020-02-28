#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int num[MAX];

int D[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		D[i] = D[i - 1] + num[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << D[b] - D[a - 1] << "\n";
	}


	return 0;
}