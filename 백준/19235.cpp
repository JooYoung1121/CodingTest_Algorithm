#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
순서는 다음과 같다.

1. 파란색 보드와 초록색 보드 각각에 블록을 바닥으로 떨군다.
2. 연한 부분에 블록이 채워졌는지 확인한다.
2-1. 만약 채워졌다면 전부다 한칸 내린다.
3. 블록이 한 줄을 채우는지 체크한다.
3-1. 만약 채워진다면 그 줄을 지워주고 위에서 아래로 떨궈준다.
4. 아래로 떨군 뒤 2를 한번 더 체크한다. (안채워질때까지)
5. 1부터 반복한다.

블록은
1 : 한개 (x,y)
2 : 1*2 (x,y)(x,y+1) ㅡ
3 : 2*1 (x,y)(x+1,y) ㅣ

// 처음에 그냥 쭉 다 내려버림
-> 그 다음 알게 된 사실은 무너진 곳 위에만 영향이 간다는 점
-> 또 충격적인것은 블록별로 다르게 처리해야 했다는 점..

처음부터 다시 풀자..

*/

int N, Result = 0;
int Block_Num = 1;

int Green_Board[6][4] = { 0, };
int Blue_Board[4][6] = { 0, };

void Green_Move(int t, int y) {

	int idx = 6;
	for (int i = 5; i >= 0; i--) {
		if (Green_Board[i][y] >= 1)
			idx = i;
	}
	if (t == 1) {
		Green_Board[idx - 1][y] = Block_Num;
	}
	else if (t == 2) { // ㅡ
		int idx = 6;
		for (int i = 5; i >= 0; i--) { // 뻘짓부분..
			if (Green_Board[i][y + 1] >= 1 || Green_Board[i][y] >= 1)
				idx = i;
		}
		Green_Board[idx - 1][y] = Block_Num;
		Green_Board[idx - 1][y + 1] = Block_Num;
	}
	else { // ㅣ
		Green_Board[idx - 1][y] = Block_Num;
		Green_Board[idx - 2][y] = Block_Num;
	}

}

void Blue_Move(int t, int x) {
	int idx = 6;
	for (int i = 5; i >= 0; i--) {
		if (Blue_Board[x][i] >= 1)
			idx = i;
	}

	if (t == 1) {
		Blue_Board[x][idx - 1] = Block_Num;
	}
	else if (t == 2) { // ㅡ
		Blue_Board[x][idx - 1] = Block_Num;
		Blue_Board[x][idx - 2] = Block_Num;
	}
	else { // ㅣ
		int idx = 6;
		for (int i = 5; i >= 0; i--) {
			if (Blue_Board[x][i] >= 1 || Blue_Board[x + 1][i] >= 1)
				idx = i;
		}
		Blue_Board[x + 1][idx - 1] = Block_Num;
		Blue_Board[x][idx - 1] = Block_Num;
	}
}

void Drop_Green(int idx) {
	int tmp[6][4] = {0,};
	for (int i = 5; i >= idx; i--) { // 아래 부분 저장 (위는 그럼 다 빈공간으로 존재하게됨)
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = Green_Board[i][j];
		}
	}


	for (int i = idx - 1; i >= 0; i--) {
		for (int yidx = 0; yidx < 4; yidx++) {
			int number = Green_Board[i][yidx];
			if (number == 0) {
				continue;
			}
			else {
				int drop_idx = 6;
				if (yidx == 0) {
					if (Green_Board[i][yidx + 1] == number) { // -
						Green_Board[i][yidx] = 0;
						Green_Board[i][yidx + 1] = 0;
						for (int j = 5; j >= 1; j--) {
							if (tmp[j][yidx] != 0 || tmp[j][yidx + 1] != 0) {
								drop_idx = j;
							}
						}
						tmp[drop_idx-1][yidx] = number;
						tmp[drop_idx-1][yidx + 1] = number;
					}
					else {
						Green_Board[i][yidx] = 0;
						for (int j = 5; j >= 1; j--) {
							if (tmp[j][yidx] != 0) {
								drop_idx = j;
							}
						}
						tmp[drop_idx-1][yidx] = number;
						if (i != 0 && Green_Board[i - 1][yidx] == number) {
							Green_Board[i - 1][yidx] = 0;
							tmp[drop_idx - 2][yidx] = number;
						}

					}
				}
				else if (yidx == 1 || yidx == 2) {
					if (Green_Board[i][yidx - 1] == number) { // -
						Green_Board[i][yidx] = 0;
						Green_Board[i][yidx - 1] = 0;
						for (int j = 5; j >= 1; j--) {
							if (tmp[j][yidx] != 0 || tmp[j][yidx - 1] != 0) {
								drop_idx = j;
							}
						}
						tmp[drop_idx-1][yidx] = number;
						tmp[drop_idx-1][yidx - 1] = number;
					}
					else if (Green_Board[i][yidx + 1] == number) { // -
						Green_Board[i][yidx] = 0;
						Green_Board[i][yidx + 1] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[j][yidx] != 0 || tmp[j][yidx + 1] != 0) {
								drop_idx = j;
							}
						}
						tmp[drop_idx-1][yidx] = number;
						tmp[drop_idx-1][yidx + 1] = number;
					}
					else { // 하나 또는 ㅣ
						Green_Board[i][yidx] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[j][yidx] != 0) {
								drop_idx = j;
							}
						}

						tmp[drop_idx-1][yidx] = number;
						if (i != 0 && Green_Board[i - 1][yidx] == number) {
							Green_Board[i - 1][yidx] = 0;
							tmp[drop_idx - 2][yidx] = number;
						}
					}
				}
				else {
					if (Green_Board[i][yidx - 1] == number) { // -
						Green_Board[i][yidx] = 0;
						Green_Board[i][yidx - 1] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[j][yidx] != 0 || tmp[j][yidx - 1] != 0) {
								drop_idx = j;
							}
						}

						tmp[drop_idx-1][yidx] = number;
						tmp[drop_idx-1][yidx - 1] = number;
					}
					else {
						Green_Board[i][yidx] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[j][yidx] != 0) {
								drop_idx = j;
							}
						}
						tmp[drop_idx-1][yidx] = number;
						if (i != 0 && Green_Board[i - 1][yidx] == number) {
							Green_Board[i - 1][yidx] = 0;
							tmp[drop_idx - 2][yidx] = number;
						}
					}
				}

			}
		}

	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			Green_Board[i][j] = tmp[i][j];
		}
	}
}

void Drop_Blue(int idx) {
	int tmp[4][6] = {0,};

	for (int i = 5; i >= idx; i--) { // 아래 부분 저장 (위는 그럼 다 빈공간으로 존재하게됨)
		for (int j = 0; j < 4; j++) {
			tmp[j][i] = Blue_Board[j][i];
		}
	}

	for (int i = idx - 1; i >= 0; i--) {
		for (int xidx = 0; xidx < 4; xidx++) {
			int number = Blue_Board[xidx][i];
			if (number == 0) {
				continue;
			}
			else {
				int drop_idx = 6;
				if (xidx == 0) {
					if (Blue_Board[xidx + 1][i] == number) { // l
						Blue_Board[xidx][i] = 0;
						Blue_Board[xidx + 1][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0 || tmp[xidx + 1][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						tmp[xidx + 1][drop_idx] = number;
					}
					else {
						Blue_Board[xidx][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						if (i != 0 && Blue_Board[xidx][i - 1] == number) {
							Blue_Board[xidx][i - 1] = 0;
							tmp[xidx][drop_idx - 1] = number;
						}
					}
				}
				else if (xidx == 1 || xidx == 2) {
					if (Blue_Board[xidx - 1][i] == number) { // l
						Blue_Board[xidx][i] = 0;
						Blue_Board[xidx - 1][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0 || tmp[xidx - 1][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						tmp[xidx - 1][drop_idx] = number;
					}
					else if (Blue_Board[xidx + 1][i] == number) { // l
						Blue_Board[xidx][i] = 0;
						Blue_Board[xidx + 1][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0 || tmp[xidx + 1][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						tmp[xidx + 1][drop_idx] = number;
					}
					else { // 하나 또는 -
						Blue_Board[xidx][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						if (i != 0 && Blue_Board[xidx][i - 1] == number) {
							Blue_Board[xidx][i - 1] = 0;
							tmp[xidx][drop_idx - 1] = number;
						}
					}
				}
				else {
					if (Blue_Board[xidx - 1][i] == number) { // -
						Blue_Board[xidx][i] = 0;
						Blue_Board[xidx - 1][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0 || tmp[xidx - 1][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						tmp[xidx - 1][drop_idx] = number;
					}
					else {
						Blue_Board[xidx][i] = 0;
						for (int j = 5; j >= 0; j--) {
							if (tmp[xidx][j] != 0) {
								drop_idx = j;
							}
						}
						drop_idx--;
						tmp[xidx][drop_idx] = number;
						if (i != 0 && Blue_Board[xidx][i - 1] == number) {
							Blue_Board[xidx][i - 1] = 0;
							tmp[xidx][drop_idx - 1] = number;
						}

					}
				}

			}
		}

	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			Blue_Board[i][j] = tmp[i][j];
		}
	}
}

bool Green_Chk() { // 1줄 채워지는지 확인 동시에 밀어줌(초록색 보드) 
	int chk = false;

	int idx = 0;
	for (int i = 5; i >= 2; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (Green_Board[i][j] >= 1)
				cnt++;
		}
		if (cnt == 4)
		{
			chk = true;
			idx = i;
			Result++;
			for (int i = 0; i < 4; i++) { // 한줄 날리기
				Green_Board[idx][i] = 0;
			}
		}
	}



	if (chk) {
		Drop_Green(idx);
	}

	return chk;
}

bool Blue_Chk() { // 1줄 채워지는지 확인 동시에 밀어줌(파란색 보드)
	int chk = false;

	int idx = 0;
	for (int i = 5; i >= 2; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (Blue_Board[j][i] >= 1)
				cnt++;
		}
		if (cnt == 4)
		{
			chk = true;
			idx = i;
			Result++;
			for (int i = 0; i < 4; i++) { // 한줄 날리기
				Blue_Board[i][idx] = 0;
			}
		}
	}

	if (chk) {
		Drop_Blue(idx);
	}

	return chk;
}

void Light_Green() { // 연한부분에 채워지면 밀어주는 곳 

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		if (Green_Board[1][i] > 0) {
			cnt++;
			break;
		}
	}
	if (cnt == 1) {
		for (int i = 0; i < 4; i++) {
			if (Green_Board[0][i] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == 1) { // 한칸 내림
		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				Green_Board[i + 1][j] = Green_Board[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			Green_Board[1][i] = 0;
		}

		Drop_Green(5);
	}
	else if (cnt == 2) { // 두칸 내림
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				Green_Board[i + 2][j] = Green_Board[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			Green_Board[0][i] = 0;
			Green_Board[1][i] = 0;
		}
		Drop_Green(5);
	}
}

void Light_Blue() { // 연한부분에 채워지면 밀어주는 곳 
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		if (Blue_Board[i][1] > 0) {
			cnt++;
			break;
		}
	}
	if (cnt == 1) {
		for (int i = 0; i < 4; i++) {
			if (Blue_Board[i][0] > 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == 1) { // 한칸 내림
		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				Blue_Board[j][i + 1] = Blue_Board[j][i];
			}
		}
		for (int i = 0; i < 4; i++) {
			Blue_Board[i][1] = 0;
		}

		Drop_Blue(5);
	}
	else if (cnt == 2) { // 두칸 내림
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				Blue_Board[j][i + 2] = Blue_Board[j][i];
			}
		}
		for (int i = 0; i < 4; i++) {
			Blue_Board[i][0] = 0;
			Blue_Board[i][1] = 0;
		}

		Drop_Blue(5);
	}
}

void green_print() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << Green_Board[i][j] << ' ';
		}
		cout << endl;
	}
}

void blue_print() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << Blue_Board[i][j] << ' ';
		}
		cout << endl;
	}
}


int main() {

	cin >> N;

	while (N--) {
		int t, x, y;
		cin >> t >> x >> y;

		Green_Move(t, y);
		Blue_Move(t, x);

		Block_Num++;

		while (Green_Chk()) {
		}
		while (Blue_Chk()) {
		}

		Light_Green();
		Light_Blue();

		while (Green_Chk()) {
		}
		while (Blue_Chk()) {
		}

		//green_print();
		//cout << endl;
		//blue_print();
		//cout << endl;
		//cout << "줄 삭제 갯수 " << Result << endl;
	}

	int Block_Count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (Green_Board[i][j])
				Block_Count++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (Blue_Board[i][j])
				Block_Count++;
		}
	}
	cout << Result << endl;
	cout << Block_Count;

	system("pause");
	return 0;
}