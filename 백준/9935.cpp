#include <iostream>
#include <string>
using namespace std;


string str, bomb;
char result[1000001];
int bomb_size;
bool chk(int idx) {
	for (int i = idx; i <idx + bomb_size; i++) {
		if (result[i] != bomb[i - idx]) return false;
	}
	return true;
}

int main() {
	
	cin >> str >> bomb;
	
	bomb_size = bomb.size();
	string tmp = str;

	int pos = 0;
	for (int i = 0; i < str.size(); i++) {
		result[pos++] = str[i];
		if (pos >= bomb_size && chk(pos - bomb_size)) {
			pos -= bomb_size;
		}
	}

	if (pos == 0)
		cout << "FRULA" << endl;
	else {
		for (int i = 0; i < pos; i++) {
			cout << result[i];
		}
	}


	system("pause");
	return 0;
}