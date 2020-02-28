#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

typedef struct data {
	bool check = false;
	int count = 0;
}D;

int main() {
	char str[51];
	int N;
	cin >> N; 
	
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		stack<int> _stack;
		D oper;
		for (int i = 0; i < strlen(str); i++) {

			if (str[i] == '(') {
				_stack.push(str[i]);
				oper.count++;
				oper.check = false;
			}
			else {
				oper.count--;
				if (oper.count < 0) {
					oper.check = false;
					break;
				}
				_stack.pop();

				if (oper.count == 0) {
					oper.check = true;
				}
			}
		}
		if (oper.check) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}


	return 0;
}