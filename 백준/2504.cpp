#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

typedef struct data {
	bool check = false;
	int small = 0;
	int big = 0;
}D;

int main() {
	char str[31];
	long long result;
	cin >> str;
	int sum = 0;
	D oper;
	stack<int> _stack;
	bool _check = true;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			_stack.push(str[i]);
			oper.small++;
			oper.check = false;
		}
		else if (str[i] == '[') {
			_stack.push(str[i]);
			oper.big++;
			oper.check = false;
		}
		else if (str[i] == ')') {
			sum = 0;
			oper.small--;
			if (oper.small < 0) {
				oper.check = false;
				break;
			}
			if (_stack.top() == '[') {
				oper.check = false;
				break;
			}
			if (_stack.top() == '(') {
				_stack.pop();
				_stack.push(2);
			}
			else {
				
				while (_stack.top() != '(') {
					if (_stack.top() == '[' || _stack.top() == ']') {
						oper.check = false;
						_check = false;
						break;
					}
					sum += _stack.top();
					_stack.pop();
				}
				if (!_check) {
					break;
				}
				sum *= 2;
				_stack.pop();
				_stack.push(sum);
			}
			if (oper.small == 0 && oper.big == 0) {
				oper.check = true;
			}
		}
		else {
			sum = 0;
			oper.big--;

			if (oper.big < 0) {
				oper.check = false;
				break;
			}
			if (_stack.top() == '(') {
				oper.check = false;
				break;
			}
			if (_stack.top() == '[') {
				_stack.pop();
				_stack.push(3);
			}
			else {
				while (_stack.top() != '[') {
					if (_stack.top() == '[' || _stack.top() == ']') {
						oper.check = false;
						_check = false;
						break;
					}
					if (!_check) {
						break;
					}
					sum += _stack.top();
					_stack.pop();
				}
				sum *= 3;
				_stack.pop();
				_stack.push(sum);
			}
			if (oper.small == 0 && oper.big == 0) {
				oper.check = true;
			}
		}
	}
	result = 0;
	if (oper.check) {
		int len = _stack.size();
		for (int i = 0; i < len; i++) {
			result += _stack.top();
			_stack.pop();
		}
		cout << result << endl;
	}
	else {
		cout << 0 << endl;
	}


	return 0;
}