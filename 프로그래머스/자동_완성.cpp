#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define NUM 26

struct Trie
{
	Trie* children[NUM];
	bool terminal = false;
	int cnt;

	Trie() :terminal(false), cnt(0)
	{
		for (int i = 0; i < NUM; ++i)
		{
			children[i] = NULL;
		}
	}

	~Trie()
	{
		for (int i = 0; i < NUM; i++)
		{
			if (children[i])
			{
				delete children[i];
			}
		}
	}

	void insert(const char* key)
	{
		//키값이 널이라면
		if (*key == 0)
		{
			terminal = true;
		}
		else
		{
			int next = *key - 'a';
			if (children[next] == NULL)
			{
				children[next] = new Trie();
			}
			children[next]->cnt++;
			children[next]->insert(key + 1);
		}
	}

	int find(const char* key, const int count)
	{

		int next = *key - 'a';

		if (*key == 0 || children[next] == NULL)
		{
			return count - 1;
		}
		if (children[next]->cnt == 1) return count;


		return children[next]->find(key + 1, count + 1);
	}

	
};

int solution(vector<string> words) {
	int answer = 0;

	Trie* trie = new Trie();

	for (int i = 0; i < words.size(); i++) {
		trie->insert(words[i].c_str());
	}

	for (int i = 0; i < words.size(); i++) {
		answer += trie->find(words[i].c_str(), 1); // 현재 문자는 하나씩 가지고 있으므로 1로 초기값 넣어줌
	}

	delete trie;
	return answer;
}

int main() {

	int N;

	cin >> N;

	vector<string> words;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	cout << solution(words);


	system("pause");
	return 0;
}