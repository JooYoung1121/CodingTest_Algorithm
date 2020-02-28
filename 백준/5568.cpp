#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

string str[11];
set<string> s;
vector<int> v;

void findfunc(int i, int k, int n, string str2) {
	if (k == 0) {
		str2 += str[i];
		s.insert(str2);
		return;
	}
	str2 += str[i];

	v[i] = 1;
	k--;
	for (int j = 0; j < n; j++) {
		if (v[j])
			continue;
		findfunc(j, k, n, str2);
		v[j] = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, n;
	string str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		v.assign(11, 0);
		str2 = "";
		findfunc(i, k - 1, n, str2);
		v.clear();
	}

	cout << s.size();
	return 0;
}