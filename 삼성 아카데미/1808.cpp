#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001
#define INF 987654321
bool chk[10];
int D[MAX];
int N;

int solve(int n) {

	int& ret = D[n];
	if (ret != 0)
		return ret;

	int tmp = n;
	int cnt = 0;
	while (tmp != 0) {
		if (!chk[tmp % 10]) {
			cnt = INF;
			break;
		}
		cnt++;
		tmp /= 10;
	}

	ret = cnt;

	for (int i = 1; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			int a = solve(i);
			int b = solve(n / i);
			if (a == INF || b == INF)
				ret = min(ret, INF);
			else
				ret = min(ret, a + b + 1);
		}
	}
	return ret;
}

int main() {

	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {

		for (int i = 0; i < 10; i++) {
			cin >> chk[i];
		}

		cin >> N;

		memset(D, 0, sizeof(D));

		int answer = solve(N);

		if (answer == INF)
			cout << "#" << test_case << " " << -1 << endl;
		else
			cout << "#" << test_case << " " << answer+1 << endl;

	}


	return 0;
}