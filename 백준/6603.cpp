#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	while (1) {

		int K;

		cin >> K;

		if (K == 0)
			break;

		vector<int> Number;

		for (int i = 0; i < K; i++) {
			int a;
			cin >> a;
			Number.push_back(a);
		}

		sort(Number.begin(), Number.end());
		vector<int> tmp;

		for (int i = 0; i < 6; i++) {
			tmp.push_back(0);
		}

		for (int i = 0; i < K-6; i++) {
			tmp.push_back(1);
		}


		do {
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp[i] == 0)
					cout << Number[i] << ' ';	
			}
			cout << endl;
		} while (next_permutation(tmp.begin(), tmp.end()));
		cout << endl;
	}


	system("pause");
	return 0;
}