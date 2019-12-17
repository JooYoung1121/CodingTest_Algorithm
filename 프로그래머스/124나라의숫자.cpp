#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int d[3] = {4,1,2};

string solution(int n) {
	string answer = "";

	while (n != 0) {
		int m;
		m = n % 3;
		answer += d[m] + '0';
		n = n / 3 - 1;
		if (m == 0)
			n--;

	}
	reverse(answer.begin(), answer.end());

	return answer;
}

int main() {

	int N;

	cin >> N;

	cout << solution(N);

	system("pause");
	return 0;
}