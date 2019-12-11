#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <Windows.h>
using namespace std;

vector<int> num;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	string n;

	cin >> n;

	int a;
	for (int i = 0; i < n.length(); i++) {
		a = n[i] - '0';
		num.push_back(a);
	}

	sort(num.begin(), num.end(),greater<int> ());

	int sum = 0;

	if (num[num.size()-1] != 0) {
		cout << -1 << "\n";
		return 0;
	}

	else {
		for (int i = 0; i < num.size()-1; i++) {
			sum += num[i];
		}
	}

	if (sum % 3 != 0) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i];
		}
	}


	system("pause");
	return 0;
}