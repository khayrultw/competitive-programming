#include <bits/stdc++.h>

using namespace std;

int main(){
    string str[5];
    str[0] = "aeiou";
    str[1] = "iaeuo";
    str[2] = "euoia";
    str[3] =  "uoaei";
    str[4] =  "oiuae";
    int n;
    cin >> n;
    int a, b;
    b = -1;
    for(a = 5; a <= n/5; a++){
        if(n%a == 0){
            b = n/a;
            break;
        }
    }
    if(b == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 5; i < a; i++){
        for(int j = 0; j < 5; j++)
            str[j] += str[j][0];
    }
    for(int i = 0; i<5; i++)
        cout << str[i];
    for(int i = 5; i<b; i++)
        cout << str[0];
    cout << endl;
    return 0;
}