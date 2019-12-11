#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
	int A, B, V;

	cin >> A >> B >> V;

	int dist = A - B;

	int result;

	result = (V - B) / dist;

	if ((V - B) % dist != 0)
		result++;

	cout << result;

	system("pause");
	return 0;
}