#include <iostream>

using namespace std;

int main()
{
	int N; // 입력 변수 2<=N<=1000000
	int result = 0;
	int pibo[30];
	int cnt,temp;
	cin >> N;
	cnt = 2;
	pibo[0] = 1;
	pibo[1] = 2;
	for (int i = 2; i < 30; i++)
	{
		pibo[i] = pibo[i - 1] + pibo[i - 2];
		cnt++;
		if (pibo[i - 1] + pibo[i - 2] > N)
		{
			break;
		}
	}
	temp = N;
	for (int i = 0; i < cnt; i++)
	{
			if (pibo[i] == N) {
				result = -1;
				break;
			}
			else
			{
				if (pibo[i] > temp) {
					if (i == 0)
						temp -= pibo[i];
					else
						temp -= pibo[i - 1];

					if (temp == 0)
					{
						if (i == 0)
							result = pibo[i];
						else
							result = pibo[i-1];
						break;
					}
					i = -1;
				}
			}
	}
	

	cout << result << endl;
	return 0;
}