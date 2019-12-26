#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000

bool visit[MAX] = { false, };

vector<string> result;

bool dfs(string from, vector<vector<string>>& tickets, vector<string>& tmp, int cnt) {
	tmp.push_back(from);

	if (cnt == tickets.size()) {
		result = tmp;
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == from && !visit[i]) {
			visit[i] = true;

			bool success = dfs(tickets[i][1], tickets, tmp, cnt + 1);
			if (success)
				return true;
			visit[i] = false;
		}
	}
	tmp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer,tmp;
	sort(tickets.begin(), tickets.end());
	dfs("ICN",tickets,tmp,0);
	answer = result;
	return answer;
}

int main() {
	int N;
	cin >> N;

	vector<vector<string>> tickets;

	for (int i = 0; i < N; i++) {
		string a, b;
		vector<string> tmp;
		cin >> a >> b;

		tmp.push_back(a);
		tmp.push_back(b);

		tickets.push_back(tmp);
	}


	vector<string> result = solution(tickets);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	system("pause");
	return 0;
}