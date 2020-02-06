#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	string num1 = "";
	string num2 = "";


	for (int i = 123; i <= 987; i++) {
		num1 = to_string(i);
		
		if (num1[0] == num1[1] || num1[1] == num1[2] || num1[0] == num1[2])
			continue;
		if (num1[0] == '0' || num1[1] == '0' || num1[2] == '0')
			continue;
		bool chk = true;
		for (int j = 0; j < baseball.size(); j++) {
			num2 = to_string(baseball[j][0]);
			int strike = 0;
			int ball = 0;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					if (a == b && num1[a] == num2[b]) {
						strike++;
						continue;
					}

					if (a != b && num1[a] == num2[b]) {
						ball++;
						continue;
					}
				}
			}
			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				chk = false;
				break;
			}
		}

		if (chk)
			answer++;
	}


	return answer;
}

int main() {

	int N;

	cin >> N;
	
	vector<vector<int>> baseball;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		baseball.push_back(tmp);
	}

	cout << solution(baseball);

	system("pause");
	return 0;
}