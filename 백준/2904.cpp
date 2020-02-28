#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 1000001
vector<int> prime;
bool _check[MAX] = {false,};


int gcd(int x, int y) {
	while (y != 0) {
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	for (int i = 2; i < MAX; i++) {
		if(!_check[i]) {
			prime.push_back(i);
		}
		for (int j = i * 2; j < MAX; j += i) {
			_check[j] = true;
		}

	}

	cin >> N;

	vector<int> count_prime(prime.size(),0);
	vector<vector<int>> sub(N,vector<int>(prime.size(),0));

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		int j = 0;
		while (1) {
			if (num%prime[j] == 0) {
				count_prime[j]++;
				sub[i][j]++;
				num /= prime[j];
				j = 0;
			}
			else {
				j++;
			}
			if (num == 1) {
				break;
			}
		}

	}

	int result = 1;
	int cnt = 0;

	for (int i = 0; i < prime.size(); i++) {
		int temp = count_prime[i] / N;
		for (int j = 0; j < temp; j++)
			result *= prime[i];
		for (int j = 0; j < N; j++)
			if (temp > sub[j][i])
				cnt += temp - sub[j][i];
	}

	cout << result << " " << cnt << "\n";

	return 0;
}