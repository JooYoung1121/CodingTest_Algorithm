#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 81

long long D[MAX];

long long solution(int N) {
	long long answer = 0;
	D[0] = 0;
	D[1] = 1;
	D[2] = 1;

	for (int i = 3; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2];
	}

	answer = (D[N] * 2) + ((D[N] + D[N - 1]) * 2);

	return answer;
}

int main() {


	int N;

	cin >> N;

	cout << solution(N);


	system("pause");
	return 0;
}