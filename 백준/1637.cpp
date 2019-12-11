#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

#define MAX 20001
#define INF 2147483647
int N;
long long A[MAX], B[MAX], C[MAX];

long long cnt(long long num) { // num까지의 빈도수 누적합 리턴
	long long ret = 0;

	for (int i = 0; i < N; i++) {
		if (num >= A[i])
			ret += (min(C[i], num) - A[i]) / B[i] + 1;
	}

	return ret;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> C[i] >> B[i];
	}
	
	long long left = 1;
	long long right = INF;

	while (left < right) {
		long long mid = (left + right) / 2;
		if (cnt(mid) % 2 == 0)
			left = mid + 1;
		else
			right = mid;
	}

	if (left == INF)
		cout << "NOTHING";
	else
		cout << left << ' ' << cnt(left) - cnt(left - 1);

	system("pause");
	return 0;
}