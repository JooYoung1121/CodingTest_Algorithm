#include <iostream>
#include <string>
using namespace std;

#define MAX 10000
int stack[MAX];
int result[MAX];

int main() {
	int N, num;
	string oper;
	cin >> N;

	int current = 0;
	int re_cu = 0;

	for (int i = 0; i < N; i++) {
		cin >> oper;

		if (oper == "push") {
			cin >> num;
			stack[current] = num;
			current++;
		}
		else if (oper == "top") {
			if (current == 0) {
				result[re_cu] = -1;
				re_cu++;
			}
			else {
				result[re_cu] = stack[current-1];
				re_cu++;
			}
		}
		else if (oper == "size") {
			result[re_cu] = current;
			re_cu++;
		}
		else if (oper == "pop") {
			if (current == 0) {
				result[re_cu] = -1;
				re_cu++;
			}
			else {
				result[re_cu] = stack[current-1];
				re_cu++;
				current--;
			}
		}
		else {
			if (current == 0) {
				result[re_cu] = 1;
				re_cu++;
			}
			else {
				result[re_cu] = 0;
				re_cu++;
			}
		}
	}

	for (int i = 0; i < re_cu; i++) {
		cout << result[i] << endl;
	}

	return 0;
}