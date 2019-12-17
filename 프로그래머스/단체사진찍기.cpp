#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char name[8] = {'A','C','F','J','M','N','R','T'};
int solution(int n, vector<string> data) {
	int answer = 0;
	vector<int> picture;
	for (int i = 0; i < 8; i++) {
		int idx = name[i] - 'A';
		picture.push_back(idx);
	}
	do {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			int p1, p2,cnt;
			char oper;
			p1 = data[i][0] - 'A';
			p2 = data[i][2] - 'A';
			cnt = data[i][4]-'0';
			oper = data[i][3];

			int idx1, idx2;
			for (int i = 0; i < 8; i++) {
				if (p1 == picture[i])
					idx1 = i;
				
				if (p2 == picture[i])
					idx2 = i;
			}

			if (idx1 < idx2)
				swap(idx1, idx2);

			if (oper == '=') {
				if ((idx1 - idx2 - 1) != cnt) {
					flag = false;
					break;
				}
			}
			else if (oper == '>') {
				if ((idx1 - idx2 - 1) <= cnt) {
					flag = false;
					break;
				}
			}
			else {
				if ((idx1 - idx2 - 1) >= cnt) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			answer++;
	} while (next_permutation(picture.begin(), picture.end()));

	return answer;
}