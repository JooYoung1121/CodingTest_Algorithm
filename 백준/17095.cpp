#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 100001

int num[MAX];
vector<int> ma[MAX];
vector<int> mi[MAX];

int ta[MAX];
int ti[MAX];

int main() {
	int N;

	cin >> N;

	int _max = 0;
	int _min = MAX;


	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		if (_max < num[i]) {
			_max = num[i];
			ma[_max].push_back(i);
		}
		else {
			if(_max == num[i])
				ma[_max].push_back(i);
		}

		if (_min > num[i]) {
			_min = num[i];
			mi[_min].push_back(i);
		}
		else {
			if(_min == num[i])
				mi[_min].push_back(i);
		}
	}

	int left = 0;
	int right = 0;

	int result = 0;

	result = ma[_max][right] - mi[_min][left];

	if (result < 0) {
		result *= -1;
		right++;
	}
	else
		left++;

	while (1) {
		if (left == mi[_min].size() || right == ma[_max].size())
			break;
		bool chk = true;
		int tmp = ma[_max][right] - mi[_min][left];
		if (tmp < 0) {
			tmp *= -1;
			chk = false;
		}
		if (result > tmp) {
			result = tmp;
			if (chk) 
				left++;
			
			else
				right++;

		}
		else {
			if (chk)
				left++;
			else
				right++;
		}

	}

	cout << result+1;


	system("pause");
	return 0;
}