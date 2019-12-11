#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int NUM = 27;

int toNumber(char n) {
	if (n == '?')
	{
		return 26;
	}

	return n - 'a';
}

struct TrieNode
{
	TrieNode* children[NUM];
	bool terminal;
	int cnt;

	TrieNode() :terminal(false), cnt(0)
	{
		for (int i = 0; i < NUM; ++i)
		{
			children[i] = NULL;
		}
	}

	~TrieNode()
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
			int next = toNumber(*key);
			if (children[next] == NULL)
			{
				children[next] = new TrieNode();
			}

			children[next]->insert(key + 1);
		}
	}

	void find(const char* key)
	{
		if (*key == 0)
		{
			cnt++;
			return;
		}

		int next = toNumber(*key);
		if (children[toNumber('?')] != NULL)
		{
			children[toNumber('?')]->find(key + 1);
		}

		if (children[next] != NULL)
		{
			children[next]->find(key + 1);
		}
	}

	int getCnt(const char* key)
	{
		if (*key == 0)
		{
			return cnt;
		}

		int next = toNumber(*key);
		if (children[next] == NULL)
		{
			return 0;
		}

		return children[next]->getCnt(key + 1);
	}
};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	TrieNode Trie;

	for (int i = 0; i < queries.size(); i++) {
		Trie.insert(queries[i].c_str());
	}

	for (int i = 0; i < words.size(); i++) {
		Trie.find(words[i].c_str());
	}

	for (int i = 0; i < queries.size(); i++) {
		answer.push_back(Trie.getCnt(queries[i].c_str()));
	}

	return answer;
}

int main() {
	vector<string> words, queries;

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		queries.push_back(tmp);
	}

	vector<int> result = solution(words, queries);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;
}