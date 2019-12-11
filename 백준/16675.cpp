#include <iostream>
#include <Windows.h>

using namespace std;

char M[2];
char T[2];

//A - Win ( 1 ) , B - Win ( -1 ) Draw ( 0 ) 
int win(char a, char b)
{
	if (a == 'R')
	{
		if (b == 'S')
			return 1;
		else if (b == 'R')
			return 0;
		else return -1;
	}
	else if (a == 'S') {
		if (b == 'S') return 0;
		else if (b == 'R') return -1;
		else return 1;
	}
	if (b == 'S') return -1;
	else if (b == 'R') return 1;
	return 0;
}

int main() {
	while (1) {
		cin >> M[0] >> M[1] >> T[0] >> T[1];

		int m;
		int t;

		if (M[0] == M[1]) {
			m = win(M[0], T[0]);
			t = win(M[0], T[1]);

			if (m == -1 || t == -1)
				cout << "TK";
			else if (m == 0 || t == 0)
				cout << "?";
			else
				cout << "MS";
		}
		else if (T[0] == T[1]) {
			m = win(M[0], T[0]);
			t = win(M[1], T[0]);

			if (m == 1 || t == 1)
				cout << "MS";
			else if (m == 0 || t == 0)
				cout << "?";
			else
				cout << "TK";
		}
		else
			cout << "?";
	}
	//S 가위 R 바위 P 보 P < R < S
	system("pause");
	return 0;
}