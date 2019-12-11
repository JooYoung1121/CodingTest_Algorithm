#include <iostream>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <vector>
using namespace std;
 // 카카오 브라이언의 고민 문제는 보류 

typedef pair<int, int> p;

string solution(string sentence) {
	string answer = "";

	char tmp1 = ' ';
	char tmp2 = ' ';

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] < 'A') {
			if (tmp1 == ' ')
				tmp1 = sentence[i];
			else if (tmp2 == ' ')
				tmp2 = sentence[i];

			if (tmp1 != ' ' && tmp2 != ' ' && tmp1 != sentence[i] && tmp2 != sentence[i]) {
				answer = "invalid";
				break;
			}
		}
		else {
			answer += sentence[i];
			if (tmp1 != ' ' && tmp2 != ' ') {
				
			}
		}
	}

	

	return answer;
}

int main() {
	string sentence;

	cin >> sentence;

	cout << solution(sentence);


	system("pause");
	return 0;
}