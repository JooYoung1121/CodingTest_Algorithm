#include <iostream>
using namespace std;

int main() {
	int N, M, result = 0;

	cin >> N >> M;

	int *num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int sum = 0;

	for (int i= 0; i < N; i++) {
		sum = 0;
		for (int j = i; j < N; j++) {
			sum += num[j];
			if (sum == M) {
				result++;
				break;
			}
			if (sum > M) {
				break;
			}
		}
	}

	cout << result << endl;

	return 0;
}