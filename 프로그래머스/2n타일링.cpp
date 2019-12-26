#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

#define MOD 1000000007


long long D[60001];

long long solution(int n) {
	long long answer = 0;

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= n; i++) {
		D[i] = (D[i-1] + D[i-2]) % MOD;
	}

	answer = D[n];

	return answer;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	system("pause");
	return 0;
}