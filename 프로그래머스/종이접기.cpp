#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;

	answer.push_back(0);

	for (int i = 1; i < n; i++) {
		vector<int> tmp;
		tmp = answer;
		answer.push_back(0);
		for (int j = 0; j < tmp.size(); j++) {
			if (j == tmp.size() / 2) {
				if (tmp[j] == 0)
					answer.push_back(1);
				else
					answer.push_back(0);
			}
			else
				answer.push_back(tmp[j]);
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> result = solution(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	system("pause");
	return 0;
}