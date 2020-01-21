#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	int test_case;

	cin >> test_case;


	while (test_case--) {
		string Key = "";

		list<char> result;
		cin >> Key;

		list<char>::iterator iter = result.begin();
		for (int i = 0; i < Key.length(); i++) {

			if (Key[i] == '<') {
				if (iter != result.begin())
					iter--;
			}
			else if (Key[i] == '>') {
				if (iter != result.end())
					iter++;
			}
			else if (Key[i] == '-') {
				if (iter != result.begin()) {
					result.erase((--iter)++);
				}
			}
			else {
				result.insert(iter, Key[i]);
			}
		}

		for (iter = result.begin(); iter != result.end(); iter++)
			cout << *iter;

		cout << '\n';
	}

	system("pause");
	return 0;
}