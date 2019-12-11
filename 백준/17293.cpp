#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

string beer[5] = {" of beer on the wall, ", " bottles of beer.", " bottle of beer.", "Take one down and pass it around, "," of beer on the wall."};

int main() {
	int N;
	cin >> N;
	int _max = N;
	while (N != 0) {

		if (N > 1) {
			cout << N << " bottles" << beer[0] << N << beer[1] << endl;
			if (N == 2)
				cout << beer[3] << N - 1 << " bottle" << beer[4] << endl;
			else
				cout << beer[3] << N - 1 << " bottles" << beer[4] << endl;

		}
		else {
			cout << N << " bottle" << beer[0] << N << beer[2] << endl;
			cout << beer[3] << "no more bottles" << beer[4] << endl;
		}
		cout << endl;
		N--;
	}

	cout << "No more bottles" << beer[0] << "no more" << beer[1] << endl;
	if(_max == 1)
		cout << "Go to the store and buy some more, " << _max << " bottle of beer on the wall." << endl;
	else
		cout << "Go to the store and buy some more, " << _max << " bottles of beer on the wall." << endl;



	system("pause");
	return 0;
}