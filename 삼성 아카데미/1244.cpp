#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string num;
int change;

int number[6];

vector<int> max_N;

int _max = 0;

void dfs(int cnt,string temp) {
	int cost = stoi(temp);
	if (max_N[cnt] >= cost)
		return;
	else
		max_N[cnt] = cost;

	if (cnt == change) {
		max_N[cnt] = max(max_N[cnt], cost);
		return;
	}
	for (int i = 0; i < temp.length()-1; i++) {
		for (int j = i+1; j < temp.length(); j++) {
			string a = temp;
			swap(a[i], a[j]);
			dfs(cnt + 1, a);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{		
		_max = 0;
		cin >> num >> change;

		max_N = vector<int>(change + 1, 0);

		if (num.length() == 2) {
			for (int i = 0; i < change; i++) {
				int tmp = number[0];
				number[0] = number[1];
				number[1] = tmp;
			}
			int result = 0;
			result += (number[0] * 10 + number[1]);
			cout << "#" << test_case << " " << result << endl;
		}
		else if(num.length() == 1) {
			cout << "#" << test_case << " " << number[0] << endl;
		}
		else {
			dfs(0, num);
			cout << "#" << test_case << " " << max_N[change] << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}