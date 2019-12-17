#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;
    vector<int> ans;
    
    for(int i=0;i<priorities.size();i++){
        printer.push(i);   
    }
    
    while(!printer.empty()){
        int now = printer.front();
        printer.pop();
        
        if(priorities[now] != *max_element(priorities.begin(),priorities.end())){
            printer.push(now);
        }
        else{
            ans.push_back(now);
            priorities[now] = 0;
        }
        
    }
    
    for(int i=0;i<ans.size();i++){
        if(location == ans[i]) return i+1;
    }
    
}