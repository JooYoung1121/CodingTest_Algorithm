#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	map<string, int> c;

	for (int i = 0; i < participant.size(); i++) {
		if (m.find(participant[i]) == m.end())
			m.insert({ participant[i],1 });
		else
			m[participant[i]]++;
	}
	for (int i = 0; i < completion.size(); i++) {
		if (c.find(completion[i]) == c.end())
			c.insert({ completion[i],1 });
		else
			c[completion[i]]++;
	}

	participant.erase(unique(participant.begin(), participant.end()), participant.end());

	for (int i = 0; i < participant.size(); i++) {
		if (c.find(participant[i]) == c.end())
		{
			answer = participant[i];
			break;
		}
		else {
			if (m[participant[i]] != c[participant[i]]) {
				answer = participant[i];
				break;
			}
		}
	}

	return answer;
	// map을 이용해서 매우 비효율적으로 짠 코드 
	// map을 이용하지 않고 소팅만으로 짠 코드 
	/*

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for(int i=0;i<completion.size();i++)
	{
	if(participant[i] != completion[i])
	return participant[i];
	}
	return participant[participant.size() - 1];

	*/

}

int main() {

	vector<string> participant, completion;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		participant.push_back(tmp);
	}

	for(int i=0;i<N-1;i++){
		string tmp;
		cin >> tmp;
		completion.push_back(tmp);
	}

	cout << solution(participant, completion);


	system("pause");

	return 0;
}
