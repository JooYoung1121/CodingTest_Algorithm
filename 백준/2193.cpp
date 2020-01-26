#include <iostream>
using namespace std;

#define MAX 91

long long D[MAX];

int main() {
	int N;
	cin >> N;

	D[1] = 1;
	D[2] = 1;

	for (int i = 3; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2];
	}

	cout << D[N];

	system("pause");
	return 0;
}