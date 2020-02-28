#include <iostream>
#include <string>
using namespace std;

#define MAX 10000
int queue[MAX];
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
			queue[current] = num;
			current++;
		}
		else if (oper == "front") {
			if (current == 0) {
				result[re_cu] = -1;
				re_cu++;
			}
			else {
				result[re_cu] = queue[0];
				re_cu++;
			}
		}
		else if (oper == "back") {
			if(current == 0) {
				result[re_cu] = -1;
				re_cu++;
			}
			else {
			result[re_cu] = queue[current - 1];
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
				result[re_cu] = queue[0];
				for (int i = 0; i < current; i++) {
					queue[i] = queue[i + 1];
				}
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