#include <iostream>
using namespace std;

int gcd(int w, int h) {
	if (h == 0)
		return w;
	else
		return gcd(h, w%h);
}


long long solution(int w, int h)
{
	long long sum = (long long)w * (long long)h;

	int _gcd = gcd(w, h);

	return sum - _gcd * ((w/_gcd) + (h/_gcd) -1);
}

int main() {
	int w, h;
	cin >> w >> h;

	cout << solution(w, h);


	system("pause");
	return 0;
}