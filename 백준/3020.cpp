#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 200001




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, H;

	cin >> N >> H;

	vector<int> top(N / 2);
	vector<int> bottom(N / 2);

	for (int i = 0; i < N/2; i++) {
		cin >> bottom[i] >> top[i];
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int result = MAX;
	int count = 1;

	for (int i = 1; i <= H; i++) {
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		temp += top.size() - (upper_bound(top.begin(), top.end(), H-i) - top.begin());

		if (result == temp) {
			count++;
		}
		else if (result > temp) {
			result = temp;
			count = 1;
		}
	}

	cout << result << " " << count;


	return 0;
}