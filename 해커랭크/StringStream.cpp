#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {

    stringstream ss(str);

    vector<int> result;

    string tmp;
    while(getline(ss,tmp,',')){
        int N;
        N = stoi(tmp);
        result.push_back(N);
    }
	// Complete this function

    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

