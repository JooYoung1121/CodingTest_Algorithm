#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define MAX 1000000000

long long gcd(long long x, long long y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}


int main() {
	int N, M;
	cin >> N;
	long long A[1001];
	int b;
	long long result = 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	bool chk = false;
	for (int i = 0; i < M; i++) {
		cin >> b;
		for (int j = 0; j < N; j++) {
			if (A[j] != 1) {
				int t = gcd(A[j], b);
				result = result * t;
				if (result >= MAX) {
					result = result % MAX;
					chk = true;
				}
				b /= t;
				A[j] /= t;
				if (b == 1) break;

			}
		}
	}
	if (chk) {
		int cnt = 1;
		for (int i = 1; i <= result; i*=10) {
			cnt++;
		}
		for (int i = 10 - cnt; i > 0; i--) {
			cout << '0';
		}
	}
	cout << result;

	
	system("pause");
	return 0;
}