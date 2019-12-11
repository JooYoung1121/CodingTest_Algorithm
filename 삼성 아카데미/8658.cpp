#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int _min = 987654321;
		int _max = 0;
		int num[10];
		vector<int> result;

		for (int i = 0; i < 10; i++) {
			int tmp;
			cin >> tmp;
			vector<int> temp;
			while (tmp != 0) {
				temp.push_back(tmp%10);
				tmp /= 10;
			}
			int sum = 0;
			for (int i = 0; i < temp.size(); i++) {
				sum += temp[i];
			}
			_max = max(_max, sum);
			_min = min(_min, sum);
		}

		cout << "#" << test_case << " " << _max << " " << _min << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}