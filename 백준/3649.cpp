#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000000

int main() {

	long long x;

	while (cin >> x) {
		int N;

		cin >> N;

		x *= MAX;
		vector<long long> lego;

		for (int i = 0; i < N; i++) {
			long long l;
			cin >> l;
			lego.push_back(l);
		}

		sort(lego.begin(), lego.end());

		long long s = 0;
		long long e = N - 1;

		while (s < e) {
			long long sum = lego[s] + lego[e];
			
			if (sum == x)
				break;
			else if (sum < x)
				s++;
			else
				e--;
		}

		if (s >= e)
			cout << "danger" << endl;
		else
			cout << "yes " << lego[s] << " " << lego[e] << endl;


	}

	return 0;
}