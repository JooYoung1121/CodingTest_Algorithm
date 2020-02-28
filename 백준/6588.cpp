#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

vector<int> prime;
bool _check[MAX] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 2; i < MAX; i++) {
		if (!_check[i]) {
			if(i % 2 != 0)
				prime.push_back(i);
		}
		for (int j = 2 * i; j < MAX; j += i) {
			_check[j] = true;
		}
	}

	int N;

	while (cin >> N) {
		if (N == 0)
			break;
		
		int sum = 0;
		int max = 0;
		bool check = false;
		int a, b;
		for (int i = 0; i < prime.size(); i++) {
			a = prime[i];
			b = N - a;
			if (!_check[b]) {
				check = true;
				break;
			}
		}
		if (!check) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
		else {
			cout << N << " = " << a << " + " << b << "\n";
		}

	}


	return 0;
}