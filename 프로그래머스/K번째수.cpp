#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int m = 0; m<commands.size(); m++) {
		int i, j, k;
		i = commands[m][0];
		j = commands[m][1];
		k = commands[m][2];
		vector<int> tmp;

		for (int a = i - 1; a<j; a++) {
			tmp.push_back(array[a]);
		}

		sort(tmp.begin(), tmp.end());

		answer.push_back(tmp[k - 1]);

	}
	return answer;
}

int main() {

	vector<int> array;
	vector<vector<int>> commands;

	int M, N;

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		array.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> tmp;
		tmp.push_back(a);
		tmp.push_back(b);
		tmp.push_back(c);

		commands.push_back(tmp);
	}

	vector<int> result = solution(array, commands);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;

}