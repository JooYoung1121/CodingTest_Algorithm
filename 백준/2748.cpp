#include <iostream>
using namespace std;

int main() {
	int N;
	long long result;
	cin >> N;

	long long* sum = new long long[N+1];
	sum[0] = 0;
	sum[1] = 1;
	for (int i = 2; i <= N; i++) {
		sum[i] = sum[i - 1] + sum[i - 2];
	}

	result = sum[N];

	cout << result << endl;


	return 0;
}
