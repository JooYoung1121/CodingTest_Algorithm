#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[26] = {false,};

int N, K, result;

vector<string> word;

void Teach(int idx,int cnt) {
	if (cnt == K) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (!visit[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				tmp++;
		}
		result = max(result, tmp);
	}
	else
	{
		for (int i = idx; i < 26; i++) {
			if (!visit[i]) {
				visit[i] = true;
				Teach(i,cnt + 1);
				visit[i] = false;
			}
		}
	}
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(tmp.substr(4, tmp.length() - 8));
	}

	if (K < 5)
		cout << 0;
	else if (K == 26)
		cout << N;
	else {
		K -= 5;
		result = 0;
		visit['a' - 'a'] = true;
		visit['n' - 'a'] = true;
		visit['t' - 'a'] = true;
		visit['i' - 'a'] = true;
		visit['c' - 'a'] = true;
		Teach(0, 0);
		cout << result;
	}

	system("pause");
	return 0;
}