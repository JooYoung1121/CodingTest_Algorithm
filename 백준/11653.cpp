#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000001;

vector<int> prime;
bool _check[MAX];


int main() {
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
	int i = 0;
	while (1) {
		if (N%prime[i] == 0) {
			cout << prime[i] << endl;
			N /= prime[i];
			i = 0;
		}
		else {
			i++;
		}
		if (N == 1) {
			break;
		}
	}

	return 0;
}