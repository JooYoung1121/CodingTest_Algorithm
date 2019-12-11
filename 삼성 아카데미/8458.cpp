#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		long long _max;

		cin >> N;

		bool flag = true;
		_max = 0;

		int state = -1;

		for (int i = 0; i < N; i++) {
			long long x, y;
			cin >> x >> y;

			long long sum = abs(x) + abs(y);

			if (state == -1) {
				state = sum % 2;
				_max = sum;
				continue;
			}

			if (state != sum % 2) {
				flag = false;
				break;
			}
			_max = max(_max, sum);
		}

		if (!flag) {
			cout << "#" << test_case << " " << -1 << "\n";
			continue;
		}
		long long low = 0;
		long long high = 100000;
		while (low <= high) {
			long long mid = (low + high) / 2;
			if ((mid * (mid + 1) / 2) >= _max)
				high = mid - 1;
			else
				low = mid + 1;
		}
		long long tmp = (low * (low + 1) / 2);
		while (tmp % 2 != state) {
			low++;
			tmp = (low * (low + 1) / 2);
		}
		cout << "#" << test_case << " " << low << "\n";
	}
	return 0;
}