#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int cnt = 1; cnt <= s.length() / 2; cnt++) {
		string result = "";
		string tmp = s.substr(0, cnt);
		int len = 1;
		int i;
		for (i = cnt; i <= s.length(); i += cnt) {
			if (tmp == s.substr(i, cnt))
				len++;
			else {
				if (len == 1)
					result += tmp;
				else
					result += (to_string(len) + tmp);
				tmp = s.substr(i, cnt);
				len = 1;
			}
		}
		i -= cnt;
		if (i != s.length())
			result += s.substr(i);

		if (answer > result.length()) answer = result.length();
	}
	return answer;
}


int main() {
	string s;
	while (1) {
		cin >> s;
		cout << solution(s);
	}
	system("pause");
	return 0;
}