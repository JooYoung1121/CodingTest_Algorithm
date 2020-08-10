#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int T;

map<string, string> Friend;
map<string, int> Friend_cnt;


string Find(string m) {
	if (m == Friend[m]) {
		return m;
	}
	else {
		return Friend[m] = Find(Friend[m]);
	}
}

void Merge(string m,string n) {
	m = Find(m);
	n = Find(n);

	if (m == n) {
		cout << Friend_cnt[m] << '\n';
		return;
	}

	Friend_cnt[m] += Friend_cnt[n];
	Friend[n] = m;
	cout << Friend_cnt[m] << '\n';

}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		int F;
		cin >> F;

		while (F--) {
			string a, b;
			cin >> a >> b;

			if (!Friend_cnt[a]) {
				Friend[a] = a;
				Friend_cnt[a]++;
			}
			
			if (!Friend_cnt[b]) {
				Friend[b] = b;
				Friend_cnt[b]++;
			}

			Merge(a, b);
		}
		Friend.clear();
		Friend_cnt.clear();

	}

	system("pause");
	return 0;
}