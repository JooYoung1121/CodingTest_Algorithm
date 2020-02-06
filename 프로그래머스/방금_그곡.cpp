#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	int _max = 0;

	for (int i = 0; i < musicinfos.size(); i++) {
		stringstream ss(musicinfos[i]);
		vector<string> ttmp;
		string tttmp;

		while (getline(ss, tttmp, ',')) {
			ttmp.push_back(tttmp);
		}
		string start_time = ttmp[0];
		string end_time = ttmp[1];
		string title = ttmp[2];
		string music = ttmp[3];

		// A A# B C C# D D# E F F# G G# #은 5개이므로 a b c d e로 가자

		string new_music = "";

		int k = 0;

		while (k != music.length()) {
			if (music[k + 1] == '#')
			{
				if (music[k] == 'A')
					new_music += 'a';
				else if (music[k] == 'C')
					new_music += 'b';
				else if (music[k] == 'D')
					new_music += 'c';
				else if (music[k] == 'F')
					new_music += 'd';
				else if (music[k] == 'G')
					new_music += 'e';
				else
					new_music += 'f';
				k += 2;
			}
			else {
				new_music += music[k];
				k++;
			}
		}

		string new_m = "";

		k = 0;

		while (k != m.length()) {
			if (m[k + 1] == '#')
			{
				if (m[k] == 'A')
					new_m += 'a';
				else if (m[k] == 'C')
					new_m += 'b';
				else if (m[k] == 'D')
					new_m += 'c';
				else if (m[k] == 'F')
					new_m += 'd';
				else if (m[k] == 'G')
					new_m += 'e';
				k += 2;
			}
			else {
				new_m += m[k];
				k++;
			}
		}

		int sh = stoi(start_time.substr(0, 2));
		int sm = stoi(start_time.substr(3, 2));
		int eh = stoi(end_time.substr(0, 2));
		int em = stoi(end_time.substr(3, 2));

		int _time;
		_time = (eh - sh) * 60 + (em - sm);

		string full_music = "";

		int a = _time / new_music.length();
		int b = _time % new_music.length();

		for (int j = 0; j < a; j++) {
			full_music += new_music;
		}
		for (int j = 0; j < b; j++) {
			full_music += new_music[j];
		}

		if (full_music.find(new_m) == std::string::npos)
			continue;
		else {
			if (_max < _time) {
				answer = title;
				_max = _time;
			}
		}
	}

	if (answer == "")
		answer = "(None)";

	return answer;
}

int main() {
	int N;

	cin >> N;

	string M;

	cin >> M;

	vector<string> musicinfos;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		musicinfos.push_back(tmp);
	}

	cout << solution(M, musicinfos);

	system("pause");
	return 0;
}