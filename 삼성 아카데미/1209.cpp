#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
int map[MAX][MAX];
int width_sum[MAX];
int height_sum[MAX];
int extra_sum[2];

int main() {

	for (int i = 0; i < 10; i++) {
		int test_case;
		cin >> test_case;

		extra_sum[0] = 0;
		extra_sum[1] = 0;

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				int num;
				cin >> num;
				sum += num;
				if (i == 0)
					height_sum[j] = num;
				else
					height_sum[j] += num;

				if (i == j)
					extra_sum[0] += num;

				if (i + j == 99)
					extra_sum[1] += num;
			}
			width_sum[i] = sum;
		}

		int _max = 0;

		for (int i = 0; i < 100; i++) {
			_max = max(_max, width_sum[i]);
			_max = max(_max, height_sum[i]);
		}
		_max = max(_max, extra_sum[0]);
		_max = max(_max, extra_sum[1]);

		cout << "#" << test_case << " " << _max << endl;
	}


	return 0;
}