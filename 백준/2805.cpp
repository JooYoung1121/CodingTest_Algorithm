#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long N, M, min = 0, max = 0;
	int result = 0;
	cin >> N >> M;

	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (num[i] > max) {
			max = num[i];
		}
	}
	long long sum = 0;
	long long mid = max / 2;
	while(min < max){
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (num[i] >= mid) {
				sum += (num[i] - mid);
			}
		}
		if (M <= sum) {
			if (result < mid) {
				result = mid;
			}
			min = mid + 1;
			mid = (max + mid) / 2;
		}
		else if (M > sum) {
			max = mid;
			mid = (min + mid) / 2;
		}
	}

	cout << result << endl;

	return 0;
}