#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long find(long long u) {
	if (!m[u]) return u;
	return m[u] = find(m[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		long long cur = room_number[i]; // 원하는 방 번호 배정이 가능할 때 
		if (!m[cur]) {
			answer.push_back(cur);
			m[cur] = find(cur + 1);
		}
		else {
			long long tmp = find(cur);
			answer.push_back(tmp);
			m[tmp] = find(tmp + 1);
		}
	}

	return answer;
}

int main() {
	long long k;
	vector<long long> room_number;

	int n;

	cin >> n;

	cin >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		room_number.push_back(a);
	}

	vector<long long> result = solution(k, room_number);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}


	system("pause");
	return 0;
}