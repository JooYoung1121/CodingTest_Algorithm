#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	vector<string> tmp, second;
	vector<int> Final[501];

	string temp;

	stringstream ss(s);

	while (getline(ss, temp, '{')) {
		if(temp != "")
			tmp.push_back(temp);
	}

	for (int i = 0; i < tmp.size(); i++) {
		stringstream ss(tmp[i]);
		while (getline(ss, temp, '}')) {
			if(temp != "" && temp != ",")
				second.push_back(temp);
		}
	}
	
	int idx = 1;

	for (auto i : second) {
		stringstream ss(i);
		while (getline(ss, temp, ',')) {
			Final[idx].push_back(stoi(temp));
		}
		idx++;
	}

	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	for (int i = 1; i < idx; i++) {
		pq.push({ Final[i].size(), i });
	}

	vector<int> Index;

	while (!pq.empty()) {
		Index.push_back(pq.top().second);
		pq.pop();
	}

	vector<int> result;
	answer.push_back(Final[Index[0]][0]);
	for (int i = 1; i<Index.size(); i++) {
		vector<int> before = Final[Index[i - 1]];
		vector<int> after = Final[Index[i]];
		int ans;

		vector<int>::iterator iter1 = before.begin();
		vector<int>::iterator iter2 = after.begin();

		for (; iter2 != after.end();) {
			if (iter1 == before.end())
				break;
			if (*iter1 == *iter2) {
				after.erase(iter2);
				iter2 = after.begin();
				iter1++;
			}
			else
				iter2++;
		}
		answer.push_back(after[0]);
	}

	return answer;
}

int main() {
	string s;

	cin >> s;

	vector<int> result = solution(s);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	system("pause");
	return 0;
}