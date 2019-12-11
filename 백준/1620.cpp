#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>a, pair<string, int>b) {
	return a.first < b.first;
}

vector<pair<string,int>> pok;
vector<string> num;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		pok.push_back({ tmp,i });
		num.push_back(tmp);
	}

	sort(pok.begin(), pok.end(),cmp);

	for (int i = 0; i < M; i++) {
		string ans;
		cin >> ans;
		int number;
		int left = 0;
		int right = N;
		int mid = (left + right) / 2;
		if (ans[0] >= 48 && ans[0] <= 57) {
			number = atoi(ans.c_str());
			cout << num[number-1] << "\n";
		}
		else {
			while (left < right) {
				if (pok[mid].first == ans) {
					cout << pok[mid].second << "\n";
					break;
				}
				else if (pok[mid].first > ans)
				{
					right = mid;
					mid = (left + right) / 2;
				}
				else
				{
					left = mid+1;
					mid = (left + right) / 2;
				}
			}
		}

	}


	system("pause");

	return 0;
}