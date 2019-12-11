#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int N, M;

	cin >> N >> M;

	int ans = 0;

	if (N > M) N -= M;
	ans = M - gcd(N, M);
	
	cout << ans;


	system("pause");
	return 0;
}