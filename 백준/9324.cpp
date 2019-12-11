#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt[26];

int main() {
	int T;
	cin >> T;

	while (T--) {
		string M;

		cin >> M;

		string result = "OK";

		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}

		for (int i = 0; i < M.length(); i++) {
			int idx = M[i] - 'A';
			cnt[idx]++;
			if (cnt[idx] == 3) {
				if (i == M.length()-1 || M[i + 1] != M[i]) {
					result = "FAKE";
					break;
				}
				else {
					cnt[idx] = 0;
					i++;
				}
			}
		}

		cout << result << endl;

	}



	system("pause");
	return 0;
}