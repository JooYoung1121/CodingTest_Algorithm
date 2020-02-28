#include <iostream>

using namespace std;

int main()
{
	int* A;
	int* B;
	int N;

	cin >> N;
	A = new int[N];
	B = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}


	for (int i = 0; i < N; i++)
	{

		B[i] = 1; // 갯수
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if (B[j] + 1 > B[i])
					B[i] = B[j] + 1;
			}
		}
	}

	int check = 0;

	for (int i = 0; i < N; i++)
	{
		if (check < B[i])
			check = B[i];
	}

	cout << check;

	return 0;
}
