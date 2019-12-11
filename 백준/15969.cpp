#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> stu;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		stu.push_back(p);
	}

	int _max = *max_element(stu.begin(), stu.end());
	int _min = *min_element(stu.begin(), stu.end());

	//auto result = minmax_element(stu.begin(),stu.end());

	//cout << *result.second - *result.first;

	cout << _max - _min;

	system("pause");
	return 0;
}