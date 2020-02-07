#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool balance_check(string u) {
	int chk = 0;
	bool start = true;
	for (auto i : u) {
		if (start) {
			if (i == '(') {
				chk++;
			}
			else
				return false;
			start = false;
		}
		else {
			if (i == '(')
				chk++;
			else
				chk--;

			if (chk < 0)
				return false;
		}
	}
	return true;
}

string solve(string w) {
	if (w == "")
		return "";

	string u = "", v = "";
	bool start = true;
	int chk = 0;
	for (int i = 0; i < w.length();i++) {
		if (start) {
			u += w[i];
			if (w[i] == '(')
				chk++;
			else
				chk--;
			start = false;
		}
		else {
			if (chk == 0) {
				v = w.substr(i);
				break;
			}
			u += w[i];
			if (w[i] == '(')
				chk++;
			else
				chk--;
		}
	} // u,v ºÐÇÒ

	if (balance_check(u)) {
		u += solve(v);
		return u;
	}
	else {
		string result;
		result += '(' + solve(v) + ')';
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(')
				result += ')';
			else
				result += '(';
		}
		return result;
	}
}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}

int main() {
	string p;
	cin >> p;

	cout << solution(p);


	system("pause");
	return 0;
}