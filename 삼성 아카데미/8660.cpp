#include<iostream>
using namespace std;

#define MOD 1000000007

int N, K;

long long D[100001][51]; // 무조건 dp문제인데 이 dp를 어찌 해야할지

long long fac(int n) {
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

long long combi(int n,int k) {
	return fac(n) / (fac(n - k)*fac(k));
}

long long solve(int p,int n) {
	long long &ret = D[p][n];

	if (p == N && n == K) return 0;

	if (ret != 0) return ret;



	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		memset(D, 0, sizeof(D));
		
		D[1][1] = 1;

		for (int i = 1; i <= N; i++) {
			if (i % 2 == 0)
				D[i][2] = 2;
		}



		long long result = solve(1, 1);
		

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}