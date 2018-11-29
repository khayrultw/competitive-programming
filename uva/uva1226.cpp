#include<bits/stdc++.h>

using namespace std;

int mod(int n, string  s){

    int tmp = 0;
    for(int i = 0; i < s.size(); i++){

        tmp = tmp*10+1;
        tmp = tmp%n;
    }
    return tmp;
}
int main(){


    int t, a, b, i;
    cin >> t;
    while(t--){

        cin >> a;
        string s;
        cin >> s;
        cout << mod(a, s) << endl;
    }
    return 0;
}
