#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the closestNumber function below.
 */
int closestNumber(int a, int b, int x) {
    /*
     * Write your code here.
     */

    int result = 0;
    long long num = pow(a,b);


    if(num == 0){
        result = 0;
    }
    else{
        int p = num / x;
        
        int dif1 = abs((x*p) - num);
        int dif2 = abs((x*(p+1)) - num);



        if(dif1 == dif2)
            result = x * p;
        else if(dif1 > dif2)
            result = x * (p+1);
        else
            result = x * p;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abx_temp;
        getline(cin, abx_temp);

        vector<string> abx = split_string(abx_temp);

        int a = stoi(abx[0]);

        int b = stoi(abx[1]);

        int x = stoi(abx[2]);

        int result = closestNumber(a, b, x);

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
