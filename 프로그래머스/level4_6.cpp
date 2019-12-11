#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 5001
#define MOD 1000000007

long long D[MAX];

int solution(int n) {
	int answer = 0;
	D[0] = 1;

	if (n % 2 == 1)
		answer = 0;
	else {
		long long sum = 0;
		for (int i = 2; i <= n; i+=2) {
			D[i] = (D[i - 2] * 3 + 2 * sum) % MOD;
			sum = (sum + D[i - 2])%MOD;
		}

		answer = D[n];
	}
	
	return answer;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	system("pause");
	return 0;
}