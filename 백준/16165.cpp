#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> girl[101];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string group;
		int K;
		cin >> group >> K;

		girl[i].push_back(group);

		for (int j = 0; j < K; j++) {
			string name;
			cin >> name;
			girl[i].push_back(name);
		}

		sort(girl[i].begin() + 1, girl[i].end());
	}



	for (int i = 0; i < M; i++) {

		string name;
		int ans;
		cin >> name >> ans;

		if (ans == 1) {
			for (int j = 0; j < N; j++) {
				string start;
				start = girl[j][0];
				for (int m = 1; m < girl[j].size();m++) {
					if (name == girl[j][m]) {
						cout << start << "\n";
						break;
					}
				}

			}
		}
		else {
			for (int j = 0; j < N; j++) {
				string start = girl[j][0];

				if (start == name) {
					for (int m = 1; m < girl[j].size(); m++) {
						cout << girl[j][m] << "\n";
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}
