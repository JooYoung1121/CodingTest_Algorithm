#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N, M, T; // 원판 갯수, 원판에 쓰인 숫자 갯수, 테스트케이스
int x, d, k; // x의 배수 원판 돌리기 , d=0 시계 d=1 반시계 , k만큼 돌리기
deque<int> circle[51];
bool visit[51][51];
int answer = 0;

void rotate(deque<int> &circle, int d, int k) {
	if (d == 0) {
		while (k--) {
			int tmp = circle.back();
			circle.push_front(tmp);
			circle.pop_back();
		}
	}
	else {
		while (k--) {
			int tmp = circle.front();
			circle.push_back(tmp);
			circle.pop_front();
		}
	}
}


bool bfs(int i, int j) {
	queue <pair<int, int>> q, v;
	q.push({ i, j });
	v.push({ i,j });
	visit[i][j] = true;

	while (!q.empty()) {
		int Num = q.front().first;
		int idx = q.front().second;
		q.pop();

		int Left_idx = idx - 1;
		int Right_idx = idx + 1;
		int Inside_Num = Num - 1;
		int Outside_Num = Num + 1;

		if (Left_idx < 0) Left_idx = M - 1;
		if (Right_idx >= M) Right_idx = 0;

		if (circle[Num][idx] == circle[Num][Left_idx]) {
			if (!visit[Num][Left_idx]) {
				visit[Num][Left_idx] = true;
				q.push({ Num,Left_idx });
				v.push({ Num,Left_idx });
			}
		}
		if (circle[Num][idx] == circle[Num][Right_idx]) {
			if (!visit[Num][Right_idx]) {
				visit[Num][Right_idx] = true;
				q.push({ Num,Right_idx });
				v.push({ Num,Right_idx });
			}
		}

		if (Inside_Num > 0) {
			if (circle[Num][idx] == circle[Inside_Num][idx]) {
				if (!visit[Inside_Num][idx]) {
					visit[Inside_Num][idx] = true;
					q.push({ Inside_Num,idx });
					v.push({ Inside_Num,idx });
				}
			}
		}

		if (Outside_Num <= N) {
			if (circle[Num][idx] == circle[Outside_Num][idx]) {
				if (!visit[Outside_Num][idx]) {
					visit[Outside_Num][idx] = true;
					q.push({ Outside_Num,idx });
					v.push({ Outside_Num,idx });
				}
			}
		}
	}

	if (v.size() == 1) {
		return false;
	}
	else {
		while (!v.empty()) {
			int num = v.front().first;
			int idx = v.front().second;
			v.pop();
			circle[num][idx] = 0;
		}
		return true;
	}
}

bool check_Adjacency() {
	memset(visit, false, sizeof(visit));
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && circle[i][j] != 0) {
				if (bfs(i, j))
					flag = true;
			}
		}
	}

	return flag;
}

pair<int, int> Calculate() {
	int Sum = 0;
	int Cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] == 0)continue;
			Sum += circle[i][j];
			Cnt++;
		}
	}

	return { Sum,Cnt };
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> N >> M >> T;


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			circle[i].push_back(a);
		}
	}



	while (T--) {
		cin >> x >> d >> k;
		for (int i = x; i <= N; i += x) { // 회전
			rotate(circle[i], d, k);
		}

		bool Flag = false;
		bool Chk = false;


		if (!check_Adjacency()) {
			pair<int, int> tmp = Calculate();
			double Avg = (double)tmp.first / (double)tmp.second;

			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (circle[i][j] == 0)continue;
					if ((double)circle[i][j] > Avg) {
						circle[i][j]--;
					}
					else if ((double)circle[i][j] < Avg) {
						circle[i][j]++;
					}
				}

			}

		}
		
		answer = Calculate().first;
	}

	cout << answer;

	system("pause");
	return 0;
}