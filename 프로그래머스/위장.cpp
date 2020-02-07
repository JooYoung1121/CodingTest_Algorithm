#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	int result = 1;
	map<string, int> Spy;

	for (auto cloth : clothes) {
		Spy[cloth[1]]++;
	}

	map<string, int>::iterator iter;
	for (iter = Spy.begin(); iter != Spy.end(); iter++) {
		result *= iter->second + 1;
	}
	answer = result - 1;

	return answer;
}


int main() {
	vector<vector<string>> clothes;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<string> ttmp;
		for (int j = 0; j < 2; j++) {
			string tmp;
			cin >> tmp;
			ttmp.push_back(tmp);
		}
		clothes.push_back(ttmp);
	}

	cout << solution(clothes);

	system("pause");
	return 0;
}