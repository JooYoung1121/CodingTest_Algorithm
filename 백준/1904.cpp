#include <iostream>
#include <Windows.h>
using namespace std;

#define MOD 15746

#define MAX 1000001

long long D[MAX];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2])%MOD;
	}

	cout << D[N]%MOD;



	system("pause");
	return 0;
}