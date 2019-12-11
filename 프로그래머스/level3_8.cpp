#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 51

int _min = 987654321;
bool visit[MAX] = { false, };

void solve(string target,string node,int cnt,vector<string>& words) {
	if (target == node) {
		_min = min(_min, cnt);
		return;
	}
	
	for (int i = 0; i < words.size(); i++) {
		int tmp = 0;

		if (visit[i])continue;
		for (int j = 0; j < node.length(); j++) {
			if (node[j] != words[i][j]) tmp++;
		}

		if (tmp != 1) continue;

		visit[i] = true;
		solve(target, words[i], cnt+1, words);
		visit[i] = false;
	}
}

int solution(string begin, string target, vector<string> words) {
	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < begin.length(); j++) {
			if (begin[j] != words[i][j]) cnt++;
		}

		if (cnt != 1) continue;

		visit[i] = true;
		solve(target, words[i], 1, words);
		visit[i] = false;
	}


	if (_min == 987654321) return 0;
	else
		return _min;
}

int main() {

	int N;
	cin >> N;

	vector<string> words;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	string begin, target;
	cin >> begin >> target;

	cout << solution(begin, target, words);


	system("pause");
	return 0;
}