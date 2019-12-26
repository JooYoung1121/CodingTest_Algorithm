#include <iostream>
using namespace std;

int main() {
	int N, S, result = 100000001;
	bool check = false;
	cin >> N >> S;

	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int sum, len;
	sum = 0;
	len = 0;
	int left = 0;

	int i = 0;

	while (i <= N) {
		if (sum >= S) {
			if (result > len) {
				check = true;
				result = len;
			}
			sum -= num[left];
			left++;
			len--;
		}
		else{
			sum += num[i];
			i++;
			len++;
		}
	}
	if (check) {
		cout << result << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}