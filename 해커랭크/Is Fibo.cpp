#include <bits/stdc++.h>

using namespace std;

long long fibo[51];


// Complete the solve function below.
string solve(long n) {
    bool chk = false;
    for(int i=0;i<51;i++){
        if(fibo[i] == n){
            chk = true;
            break;
        }    
    }

    if(chk)
        return "IsFibo";
    else
        return "IsNotFibo";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2;i<51;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if(fibo[i] > 10000000000)
            break;
    }
    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
