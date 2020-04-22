#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

deque<int> Circle[5];
int K;
int Result = 0;

void rotate(int Idx,int Dir){
	if(Dir == 1){ // 시계 방향
		int tmp = Circle[Idx][7];
		Circle[Idx].pop_back();
		Circle[Idx].push_front(tmp);
	}else{ // 반시계 방향
		int tmp = Circle[Idx][0];
		Circle[Idx].pop_front();
		Circle[Idx].push_back(tmp);
	}
}

void solve(int Idx,int Dir){
	vector<pair<int,int>> chk; // Idx,Dir
	if(Idx == 1){
		chk.push_back({Idx,Dir});
		if(Circle[1][2] != Circle[2][6]){
			chk.push_back({2,-Dir});
			if(Circle[2][2] != Circle[3][6]){
				chk.push_back({3,Dir});
				if(Circle[3][2] != Circle[4][6])
					chk.push_back({4,-Dir});
			}
			
		}
		
		
		
	}
	else if(Idx == 2 || Idx == 3){
		if(Idx == 2){
			chk.push_back({Idx,Dir});
			if(Circle[1][2] != Circle[2][6]){
				chk.push_back({1,-Dir});
			}
			
			if(Circle[2][2] != Circle[3][6]){
				chk.push_back({3,-Dir});
				if(Circle[3][2] != Circle[4][6])
					chk.push_back({4,Dir});
			}
			
		}
		else{
			chk.push_back({Idx,Dir});
			if(Circle[2][2] != Circle[3][6]){
				chk.push_back({2,-Dir});
				if(Circle[1][2] != Circle[2][6])
					chk.push_back({1,Dir});
			}
			if(Circle[4][6] != Circle[3][2]){
				chk.push_back({4,-Dir});
			}
		}
		
	}
	else{
		chk.push_back({Idx,Dir});
		if(Circle[3][2] != Circle[4][6]){
			chk.push_back({3,-Dir});
			if(Circle[2][2] != Circle[3][6]){
				chk.push_back({2,Dir});	
				if(Circle[1][2] != Circle[2][6]){
					chk.push_back({1,-Dir});
				}
			}
		}
		
		
	}
	
	for(int i=0;i<chk.size();i++){
			rotate(chk[i].first,chk[i].second);
	}
}

int main(){
	string Saw;
	
	for(int i=1;i<=4;i++){
		cin >> Saw;
		for(auto s : Saw){
			Circle[i].push_back(s - '0');
		}
	}
	cin >> K;
	while(K--){
		int Num,Dir;
		cin >> Num >> Dir;
		solve(Num,Dir);
	}
	
	if(Circle[1][0] == 1) Result += 1;
	if(Circle[2][0] == 1) Result += 2;
	if(Circle[3][0] == 1) Result += 4;
	if(Circle[4][0] == 1) Result += 8;
	
	cout << Result;
	return 0;
}