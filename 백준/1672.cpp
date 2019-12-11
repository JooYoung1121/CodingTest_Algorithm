#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <Windows.h>
using namespace std;

#define MAX 1000001

int D[MAX];
int s[MAX];
//A 1 G 2 C 3 T 4

int table[4][4] = { {1,3,1,2},{3,2,4,1},{1,4,3,2},{2,1,2,4} };

int main() {
	int N;

	cin >> N;

	string DNA;

	cin >> DNA;

	reverse(DNA.begin(), DNA.end());

	for (int i = 0; i < DNA.length(); i++) {
		if (DNA[i] == 'A')
			s[i + 1] = 1;
		else if (DNA[i] == 'G')
			s[i + 1] = 2;
		else if (DNA[i] == 'C')
			s[i + 1] = 3;
		else
			s[i + 1] = 4;
	}


	D[1] = s[1];
	for (int i = 2; i <= N; i++) {
		D[i] = table[D[i - 1] - 1][s[i] - 1];
	}

	if (D[N] == 1)
		cout << 'A';
	else if (D[N] == 2)
		cout << 'G';
	else if (D[N] == 3)
		cout << 'C';
	else
		cout << 'T';
	

	system("pause");
	return 0;

}