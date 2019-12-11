#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <Windows.h>

using namespace std;

vector<int> card;
int number[20000001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;

	cin >> N;
	memset(number, 0, sizeof(number));
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		card.push_back(num);
		if (num < 0) {
			num *= -1;
			num += 10000000;
			number[num]++;
		}
		else
			number[num]++;
	}

	sort(card.begin(), card.end());

	
	int M;

	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		int left = 0;
		int right = N;
		int mid = (left + right) / 2;
		int cnt = 0;
		bool chk = false;
		while (left < right) {
			if (card[mid] == num) {
				if (num < 0)
				{
					num *= -1;
					num += 10000000;
					cout << number[num] << " ";
				}
				else
					cout << number[num] << " ";
				chk = true;
				break;
			}
			else if (card[mid] < num) {
				left = mid + 1;
				mid = (left + right) / 2;
			}
			else {
				right = mid;
				mid = (left + right) / 2;
			}
		}
		if (!chk)
			cout << 0 << " ";
	}

	system("pause");
	return 0;
}