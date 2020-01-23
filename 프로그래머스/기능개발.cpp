#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	vector<int> time;

	for (int i = 0; i < speeds.size(); i++) {
		
		int diff = 100 - progresses[i];

		int div = diff / speeds[i];

		if (diff % speeds[i] != 0)
			div++;

		time.push_back(div);
	}

	int tmp = time[0];
	int cnt = 1;
	for (int i = 1; i < time.size(); i++) {
		if (tmp < time[i]) {
			tmp = time[i];
			answer.push_back(cnt);
			cnt = 1;
		}
		else
			cnt++;
	}

	answer.push_back(cnt);

	return answer;
}

int main() {
	vector<int> progresses, speeds;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		progresses.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		speeds.push_back(s);
	}


	vector<int> result;
	result = solution(progresses, speeds);


	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	system("pause");
	return 0;

}