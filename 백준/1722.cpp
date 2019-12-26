#include <iostream>
using namespace std;

long long num[21];
bool isVisit[21] = { false, };

long long fac(int n) {
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int N, problem;
	cin >> N;
	long long result[21];
	cin >> problem;

	if (problem == 1) {
		long long K;
		cin >> K;
		for (int j = 1; j <= N; j++) {
			int count = 1;
			for (int i = 1; i <= N; i++) {
				if (isVisit[i]) continue;
				if ((fac(N - j)*count) >= K) {
					isVisit[i] = true;
					K -= (fac(N - j)*(count - 1));
					result[j] = i;
					break;
				}
				count++;
			}
		}
		for (int i = 1; i <= N; i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
	}
	else if(problem == 2) {
		long long K = 1;
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
			int count = 0;
			for (int j = 1; j < num[i]; j++) {
				if (!isVisit[j])
					count++;
			}
			K += count*fac(N - i);
			isVisit[num[i]] = true;
		}
		cout << K << endl;
	}

	return 0;
}