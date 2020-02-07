#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define num 10

struct Trie {
	bool end;
	Trie* Pon[num];
	Trie() {
		for (int i = 0; i < num; i++)
			Pon[i] = 0;
		end = false;
	}
	~Trie() {
		for (int i = 0; i < num; i++)
			if (Pon[i] != 0)
				delete Pon[i];
	}

	void insert(const char* str) {
		if (*str == '\0') {
			end = true;
			return;
		}
		int cur = *str - '0';
		if (Pon[cur] == 0)
			Pon[cur] = new Trie();
		Pon[cur]->insert(str + 1);
	}

	bool find(const char* str) {
		if (*str == '\0')
			return true;
		if (end) return false;
		int idx = *str - '0';
		return Pon[idx]->find(str + 1);
	}

};



bool solution(vector<string> phone_book) {
	bool answer = true;

	Trie* trie = new Trie();
	for (auto phone : phone_book) {
		trie->insert(phone.c_str());
	}

	for (auto phone : phone_book) {
		if (!trie->find(phone.c_str())) {
			answer = false;
			break;
		}
	}

	return answer;
}
int main() {

	int N;
	cin >> N;

	vector<string> phone_book;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		phone_book.push_back(tmp);
	}

	cout << solution(phone_book);

	system("pause");
	return 0;
}