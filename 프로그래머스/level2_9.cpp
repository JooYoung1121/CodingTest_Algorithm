#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


struct info {
	string head, number, tail;
	string cmp_head;
};

bool chk(info a, info b) {
	if (a.cmp_head == b.cmp_head) {
		return stoi(a.number) < stoi(b.number);
	}
	else {
		return a.cmp_head < b.cmp_head;
	}
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	vector<info> v;


	for (int i = 0; i < files.size(); i++) {
		string file = files[i];
		info a;
		int j = 0;
		for (; j < file.length(); j++) {
			if (file[j] < '0' || file[j] > '9')
				a.head += file[j];
			else
				break;
		}

		for (; j < file.length(); j++) {
			if (file[j] >= '0' && file[j] <= '9')
				a.number += file[j];
			else
				break;
		}

		for (; j < file.length(); j++) {
			a.tail += file[j];
		}

		for (int j = 0; j < a.head.length(); j++) {
			a.cmp_head += toupper(a.head[j]);
		}
		v.push_back(a);
	}

	sort(v.begin(), v.end(), chk);

	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].head + v[i].number + v[i].tail);
	}

	return answer;
}

int main() {

	vector<string> files;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		getline(cin, tmp);
		files.push_back(tmp);
	}

	vector<string> result = solution(files);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;
}