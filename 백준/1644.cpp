#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000001

vector<int> prime;
bool _check[MAX] = { false, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i < MAX; i++) {
		if (!_check[i]) {
			prime.push_back(i);
		}
		for (int j = i * 2; j < MAX; j += i) {
			_check[j] = true;
		}
	}
	int N;

	cin >> N;

	int left = 0;
	int count = 0;
	int sum;
	int i = 0;

	while (i < prime.size()) {
		sum = 0;
		for (int j = left; j <= i; j++) {
			sum += prime.at(j);
		}

		if (sum == N) {
			count++;
			i++;
		}
		else if(sum > N) {
			left++;
		}
		else {
			i++;
		}
	}

	cout << count << "\n";

	
	return 0;
}