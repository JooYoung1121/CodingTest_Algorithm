#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> possible_list[100], temp;
set<set<string>> result;
bool visit[10] = {false,};
int answer = 0;

int banned_size;


void dfs(int cnt,vector<string>& user_id) {
	if (cnt == banned_size) {
		set<string> tmp;
		for (string t : temp) {
			tmp.insert(t);
		}
		if (result.count(tmp) == 0) {
			answer++;
			result.insert(tmp);
		}
	}

	for (int i = 0; i < possible_list[cnt].size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (!visit[j] && possible_list[cnt][i] == user_id[j]) {
				visit[j] = true;
				temp.push_back(user_id[j]);
				dfs(cnt + 1, user_id);
				temp.pop_back();
				visit[j] = false;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	
	int idx = 0;
	banned_size = banned_id.size();
	for (string banned : banned_id) {
		for (string user : user_id) {
			bool chk = true;
			if (banned.length() != user.length())continue;
			for (int i = 0; i < user.length(); i++) {
				if (user[i] != banned[i] && banned[i] != '*') {
					chk = false;
					break;
				}
			}
			if (chk)
				possible_list[idx].push_back(user);
		}
		idx++;
	}

	dfs(0, user_id);


	return answer;
}

int main() {
	vector<string> user_id, banned_id;

	int M, N;

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		user_id.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		banned_id.push_back(tmp);
	}

	cout << solution(user_id, banned_id);

	system("pause");
	return 0;
}