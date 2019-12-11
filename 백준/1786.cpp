#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);

	int T_size, P_size;
	T_size = T.length();
	P_size = P.length();

	vector<int> chk(P_size,0);
	int j = 0;

	for (int i = 1; i < P_size; i++) {
		while (j > 0 && P[i] != P[j]) j = chk[j - 1];
		if (P[i] == P[j]) chk[i] = ++j;
	}

	j = 0;

	vector<int> result;

	for (int i = 0; i < T_size; i++) {
		while (j > 0 && T[i] != P[j]) j = chk[j - 1];
		if (T[i] == P[j]) {
			if (j == P_size-1) {
				result.push_back(i - P_size + 2);
				j = chk[j];
			}
			else j++;
		}
	}

	cout << result.size() << endl;

	for (int m : result) {
		cout << m << ' ';
	}

	system("pause");
	return 0;
}