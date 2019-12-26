#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1e6 + 3;

string P;
int K;

vector<int> prime[MAX];

int mod(int p)
{
	int ret = 0;
	for (int i = 0; P[i]; i++) {
		ret = (ret * 10 + (P[i] - '0')) % p;
	} 
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool _check[MAX] = { false, };
	
	for (int i = 2; i < MAX; i++) {
		if (!_check[i]) {
			prime->push_back(i);
		}
		for (int j = 2 * i; j < MAX; j += i) {
			_check[j] = true;
		}
	}

	cin >> P >> K;

	for (int i = 0; i < prime->size(); i++) {
		if (prime->at(i) >= K) break;
		if (mod(prime->at(i)) == 0) {
			cout << "BAD" << " " << prime->at(i) << "\n";
			return 0;
		}
	}
	cout << "GOOD" << "\n";
	return 0;
}