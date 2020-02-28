#include <iostream>
using namespace std;

int main()
{
	int sum[5];
	int in, re;
	re = 0;
	int n = 0;
	int k = 0;
	while (1)
	{
		cin >> in;
		re += in;
		n++;

		if (n == 4) {
			sum[k] = re;
			k++;
			re = 0;
			n = 0;
		}
		if (k == 5)
			break;
		
	}
	int temp,cnt;
	temp = sum[0];
	cnt = 1;
	for (int i = 1; i < 5; i++)
	{
		if (temp < sum[i])
		{
			temp = sum[i];
			cnt = i+1;
		}
	}

	cout << cnt << ' ' << sum[cnt - 1] << endl;


	return 0;
}