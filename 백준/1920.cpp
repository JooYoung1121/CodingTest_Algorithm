#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;

	cin >> N;
	A.push_back(0);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	int M;

	cin >> M;
	int ans;

	
	for (int i = 1; i <= M; i++) {
		cin >> ans;
		int _max = N;
		int _min = 1;
		int mid = (_max + _min) / 2;
		bool chk = false;

		while (_min <= _max) {
			if (A[mid] == ans) {
				cout << 1 << "\n";
				chk = true;
				break;
			}
			else {
				if (_min == _max)
					break;
				if (A[mid] > ans) {
					_max = mid;
					mid = (_max + _min) / 2;
				}
				else {
					_min = mid + 1;
					mid = (_max + _min) / 2;
				}
			}
		}
		
		if (!chk)
			cout << "0" << "\n";

	}

	
	system("pause");
	return 0;
}