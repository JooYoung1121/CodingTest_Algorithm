#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> mp;
	map<string, int>::iterator iter;

	for (int i = 0; i < genres.size(); i++) {
		iter = mp.find(genres[i]);
		if (iter != mp.end()) {
			mp[genres[i]] = iter->second + plays[i];
		}
		else {
			mp.insert({genres[i],plays[i]});
		}
	}

	map<int, string> rev;
	map<int, string>::iterator it;

	for (iter = mp.begin(); iter != mp.end(); iter++) {
		rev.insert({-(iter->second),iter->first});
	}

	vector<pair<int, int>> arr;

	for (it = rev.begin(); it != rev.end(); it++) {
		string tmp = it->second;
		arr.clear();
		for (int i = 0; i < genres.size(); i++) {
			if (tmp == genres[i])
				arr.push_back({ -plays[i], i });
		}

		sort(arr.begin(), arr.end());

		if (arr.size() == 1)
			answer.push_back(arr[0].second);
		else {
			answer.push_back(arr[0].second);
			answer.push_back(arr[1].second);
		}
		
	}


	return answer;
}

int main() {
	vector<string> genres;
	vector<int> plays;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		genres.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		plays.push_back(a);
	}

	vector<int> result = solution(genres, plays);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	system("pause");
	return 0;
}