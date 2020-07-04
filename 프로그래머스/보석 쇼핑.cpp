#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

set<string> Gem_List; // 보석 종류
map<string, int> Gem_Cnt; // 각 보석이 몇개씩 있는지 확인 

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	for (string gem : gems) { // 보석 종류 저장 (중복 제거)
		Gem_List.insert(gem);
	}

	int left = 0;
	int right = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	deque<string> total_list;

	while (left <= gems.size() - Gem_List.size()) {
		if (Gem_Cnt.size() == Gem_List.size()) {
			pq.push({ total_list.size(),left });
			bool chk = false;
			for (int i = left; i < right; i++) {
				if (Gem_Cnt[gems[i]] > 1) {
					left++;
					Gem_Cnt[gems[i]]--;
					total_list.pop_front();
					chk = true;
				}
				else {
					break;
				}
			}

			if (chk) {
				pq.push({ total_list.size(),left });
			}
			else {
				if (right > gems.size() - 1) {
					Gem_Cnt[gems[left]]--;
					if (!Gem_Cnt[gems[left]])
						break;
					total_list.pop_front();
					left++;
				}
				else {
					Gem_Cnt[gems[right]]++;
					total_list.push_back(gems[right]);
					right++;
				}
			}
		}
		else {
			if (right > gems.size() - 1) {
				Gem_Cnt[gems[left]]--;
				if (!Gem_Cnt[gems[left]])
					break;
				total_list.pop_front();
				left++;
			}
			else {
				Gem_Cnt[gems[right]]++;
				total_list.push_back(gems[right]);
				right++;
			}
		}
	}
	answer.push_back(pq.top().second + 1);
	answer.push_back(pq.top().second + pq.top().first);

	return answer;
}