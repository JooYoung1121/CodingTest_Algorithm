#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 1001

char a[MAX];
vector<char> result;

string solution(int n, int t, int m, int p) {
	string answer = "";

	int cnt = 0;
	int tmp = cnt;
	while (1) {
		bool chk = false;
		int _size = 0;
		cnt = tmp;
		if (cnt == 0) {
			a[0] = 0 + '0';
			_size++;
		}
		while (cnt != 0) {
			a[_size] = (cnt%n) + '0';
			cnt /= n;
			_size++;
		}

		for (int i = 0; i < _size; i++) {
			if (a[i] > 57) {
				if (a[i] == 58) a[i] = 'A';
				else if (a[i] == 59) a[i] = 'B';
				else if (a[i] == 60) a[i] = 'C';
				else if (a[i] == 61) a[i] = 'D';
				else if (a[i] == 62) a[i] = 'E';
				else a[i] = 'F';
			}
		}

		for (int i = _size-1; i >= 0; i--) {
			result.push_back(a[i]);
		}
		if (result.size() >= t * m)
			break;

		tmp++;
	}

	cnt = 0;

	for (int i = p-1; i < result.size(); i+=m) {
		if (cnt == t)break;
		answer += result[i];
		cnt++;
	}

	return answer;
}

int main() {
	int n, t, m, p;

	cin >> n >> t >> m >> p;

	cout << solution(n, t, m, p);

	system("pause");
	return 0;
}