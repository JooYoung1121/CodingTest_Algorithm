#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500001

struct info {
	int power, idx;
};

info P[MAX], tmp[MAX];
int A[MAX];

void msort(int left, int right)
{
	if (right == left)return;
	else if (right - left == 1)
	{
		if (P[left].power < P[right].power)
		{
			A[P[right].idx]--;
			info p = P[right];
			P[right] = P[left];
			P[left] = p;
		}
	}
	else
	{
		int l = left;
		int mid = (left + right) / 2;
		int r = mid + 1;
		msort(l, mid);
		msort(r, right);
		for (int i = left; i <= right; i++)
		{
			if (l>mid) tmp[i] = P[r++];
			else if (r>right) tmp[i] = P[l++];
			else if (P[l].power > P[r].power) tmp[i] = P[l++];
			else
			{
				A[P[r].idx] -= (mid - l + 1);
				tmp[i] = P[r++];
			}
		}
		for (int i = left; i <= right; i++) P[i] = tmp[i];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i].power;
		P[i].idx = A[i] = i;
	}

	msort(1, N);

	for (int i = 1; i <= N; i++) {
		cout << A[i] << '\n';
	}

	system("pause");
	return 0;
}