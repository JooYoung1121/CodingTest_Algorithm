#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		int cnt = 0;
		string cur = skill_trees[i];
		vector<int> loc;
		bool chk = true;
		for (int j = 0; j < cur.size(); j++) {
			int idx = skill.find(cur[j]);
			if (idx == string::npos)
				continue;
			if (idx != cnt) {
				chk = false;
				break;
			}
			else
				cnt++;

		}
		if (chk)
			answer++;
	}

	return answer;
}

int main() {
	int N;
	cin >> N;

	vector<string> skill_trees;

	string skill;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		skill_trees.push_back(tmp);
	}

	cin >> skill;

	cout << solution(skill, skill_trees);

	system("pause");
	return 0;
}