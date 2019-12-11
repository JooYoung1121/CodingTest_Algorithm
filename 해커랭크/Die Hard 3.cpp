#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int gcd(int a,int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Complete the solve function below.
string solve(int a, int b, int c) {

    if(c % gcd(a,b) == 0 && c <= max(a,b))
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abc_temp;
        getline(cin, abc_temp);

        vector<string> abc = split_string(abc_temp);

        int a = stoi(abc[0]);

        int b = stoi(abc[1]);

        int c = stoi(abc[2]);

        string result = solve(a, b, c);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
