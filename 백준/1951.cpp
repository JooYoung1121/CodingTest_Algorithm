#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long result;
	int N,M;
	int cnt;
	cnt = 0;
	result = 0;
	cin >> N;
	M = N;
	while (1)
	{
		if (cnt == 0 && M < 10)
			break;

		M /= 10;
		cnt++;
		if (M < 10)
			break;
	}

	for(int i=0;i<cnt;i++)
		result += (9 * pow(10, i))*(i + 1);

	if (cnt == 0)
		result = N;
	else
	{
		result += ((N - pow(10, cnt))+1)*(cnt+1);
	}

	cout << result % 1234567 << endl;


	return 0;
}