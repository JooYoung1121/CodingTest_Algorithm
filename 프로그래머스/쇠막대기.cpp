#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int solution(string arrangement) {
	int answer = 0;

	stack<char> check;
	
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(')
			check.push(arrangement[i]);
		else {
			check.pop();
			if (arrangement[i - 1] == '(')
				answer += check.size();
			else
				answer++;
		}
	}
	return answer;
}

int main() {

	string arrangement;
	cin >> arrangement;

	cout << solution(arrangement);

	system("pause");
	return 0;
}