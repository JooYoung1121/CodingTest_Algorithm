#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


string solution(string number, int k) {
	string answer = "";
	int need = number.length() - k;
	int _max = 0;
	int cnt = 0;
	vector<int> temp;
	for (int i = need; i > 0; i--) {
		_max = 0;
		cnt = 0;
		for (int j = 0; j < number.length() - i + 1; j++) {
			if (_max < number[j]) {
				_max = number[j];
				cnt = j;
			}
		}
		number.replace(0, cnt + 1, " ");
		temp.push_back(_max);
	}
	for (int i = 0; i < temp.size(); i++)
		answer += temp[i];
	return answer;
}

int main() {


	string number;
	cin >> number;
	int k;
	cin >> k;

	cout << solution(number, k);


	system("pause");
	return 0;
}