#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> Dwarf;

	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		Dwarf.push_back(a);
	}

	vector<int> tmp;

	for (int i = 0; i < 7; i++) {
		tmp.push_back(0);
	}

	for (int i = 0; i < 2; i++) {
		tmp.push_back(1);
	}

	sort(Dwarf.begin(), Dwarf.end());

	do {

		vector<int> result;
		int sum = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == 0) {
				sum += Dwarf[i];
				result.push_back(Dwarf[i]);
			}
		}

		if (sum == 100)
		{
			for (int i = 0; i < result.size(); i++) {
				cout << result[i] << endl;
			}
			break;
		}

	} while (next_permutation(tmp.begin(), tmp.end()));


	system("pause");
	return 0;
}