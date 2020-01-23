#include <iostream>
using namespace std;

#define MOD 10007

int D[1001];

int main() {

	int N;

	cin >> N;

	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2])%MOD;
	}
	cout << D[N];
	return 0;
}