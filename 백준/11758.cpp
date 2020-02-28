#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> a,b,c;

	cin >> a.first;
	cin >> a.second;
	cin >> b.first;
	cin >> b.second;
	cin >> c.first;
	cin >> c.second;

	int result = (a.first*b.second + b.first*c.second + c.first* a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);

	if (result < 0) {
		cout << -1;
	}
	else if (result > 0) {
		cout << 1;
	}
	else
		cout << result;

	return 0;
}