#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int solution(vector<string> lines) {
	int answer = 0;

	int Hour, Minute, Second, Micro, Process,end;

	priority_queue<int, vector<int>, greater<int>> start_process, end_process;

	for (int i = 0; i < lines.size(); i++) { // Micro 단위로 시간을 변환시키는 부분
		Hour = atoi(lines[i].substr(11, 2).c_str());
		Minute = atoi(lines[i].substr(14, 2).c_str());
		Second = atoi(lines[i].substr(17, 2).c_str());
		Micro = atoi(lines[i].substr(20, 3).c_str());
		end = 3600 * 1000 * Hour + 60 * 1000 * Minute + 1000 * Second + Micro;
		Process = 1000*atof(lines[i].substr(24, lines[i].length() - 25).c_str());
		start_process.push(end - Process + 1); // 시작 시간
		end_process.push(end); // 종료 시간
	}

	int start_time, end_time; // 구간 설정
	int Count = 0;

	end_time = end_process.top();
	start_process.pop();
	Count++;
	answer = max(answer, Count);
	start_time = end_time - 999;
	while (end_time != end + 1) {
		while (!start_process.empty() && start_process.top() <= end_time) {
			start_process.pop();
			Count++;
		}

		answer = max(answer, Count);

		while (!end_process.empty() && end_process.top() <= start_time) {
			end_process.pop();
			Count--;
		}
		start_time++;
		end_time++;
	}


	return answer;
}

int main() {

	vector<string> lines;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		string tmp;
		getline(cin, tmp);
		if(i != 0)
			lines.push_back(tmp);
	}

	cout << solution(lines);


	system("pause");
	return 0;
}