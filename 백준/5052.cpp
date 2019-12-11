#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <Windows.h>
using namespace std;

#pragma warning(disable: 4996)

#define num 10

char phone[10000][11];

struct Trie {
	bool end;
	Trie* pon[num];

	Trie() {
		for (int i = 0; i < num; i++) {
			pon[i] = 0;
		}
		end = false;
	}
	~Trie() {
		for (int i = 0; i < num; i++) {
			if (pon[i] != 0)
				delete pon[i];
		}
	}

	void insert(const char* str) {
		if (*str == '\0')
		{
			end = true;
			return;
		}
		int cur = *str - '0';
		if (pon[cur] == 0)
			pon[cur] = new Trie();
		pon[cur]->insert(str + 1);
	}

	bool find(const char* str) {
		if (*str == '\0')
			return true;

		if (end) return false;

		int index = *str - '0';
		return pon[index]->find(str + 1);
	}

};

int main() {
	int T;

	cin >> T;

	while (T--) {
		int N;

		cin >> N;

		Trie* trie = new Trie();
		for (int i = 0; i < N; i++) {
			scanf("%s", &phone[i]);
			trie->insert(phone[i]);
		}

		bool result = true;
		for (int i = 0; i < N; i++) {
			if (!trie->find(phone[i]))
			{
				result = false;
				break;
			}
		}
			
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	system("pause");
	return 0;
}