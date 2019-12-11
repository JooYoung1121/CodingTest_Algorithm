#include <iostream>
using namespace std;


/*
* Complete the halloweenParty function below.
*/
long long halloweenParty(int k) {
    long long a = k / 2;

    if(k % 2 == 0){
        return a * a;
    }
    else{
        return a * (a + 1);
    }
}

int main()
{
    int t;
    cin >> t;
   
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int k;
        cin >> k;

        long long result = halloweenParty(k);

        cout << result << endl;
    }


    return 0;
}
