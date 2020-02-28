#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 1000001

int Arr[MAX];
pair<int, int> D[MAX];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	stack<int> s;
	int N;
	cin >> N;
	int len = 0;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		int* lower_pos = lower_bound(Arr, Arr + len, num);
		int _pos = int(lower_bound(Arr, Arr + len, num) - Arr);
		if (*lower_pos == 0) len++;
		*lower_pos = num;
		D[i].first = _pos;
		D[i].second = num;
	}

	cout << len << "\n";

	for (int i = N; i >0; i--) {
		if (D[i].first == len - 1) {
			s.push(D[i].second);
			len--;
		}
	}

	while (s.size()) {
		cout << s.top() << ' ';
		s.pop();
	}
}