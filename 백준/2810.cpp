#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;

	cin >> N;

	string cup;

	cin >> cup;

	string result = "";

	result += "*";

	int idx = 0;

	while (idx < N) {
		if (cup[idx] == 'S') {
			result += "S*";
			idx++;
		}
		else {
			result += "LL*";
			idx += 2;
		}
	}

	int cnt = 0;
	int scnt = 0;
	for (int i = 0; i < result.length(); i++) {
		if (result[i] == '*')
			cnt++;
		if (result[i] == 'S')
			scnt++;
	}
	if (scnt == N)
		cnt--;
	cout << cnt;

	system("pause");
	return 0;
}