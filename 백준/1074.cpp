#include <iostream>
#include <Windows.h>
#include <math.h>
#include <algorithm>
using namespace std;

int cnt = 0;

void solve(int n, int r, int c) {
	int l;

	l = pow(2, n - 1);
	if (r >= l) cnt += pow(4, n - 1) * 2;
	if (c >= l) cnt += pow(4, n - 1);
	if (r > 0 || c > 0) {
		if (r >= l)
			r -= l;
		if (c >= l)
			c -= l;
		solve(n-1, r, c);
	}
	else
		return ;

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, r, c;

	cin >> N >> r >> c;

	solve(N, r, c);

	cout << cnt;

	system("pause");
	return 0;
}