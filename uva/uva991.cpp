#include<bits/stdc++.h>

using namespace std;

#define i64 long long

i64 catalan(i64 n){

    if(n==0)
        return 1;
    i64 tmp = catalan(n-1);
    return (4*n-2)*tmp/(n+1);
}

int main(){

    i64 n;
    bool f = false;
    while(cin>>n){

        if(f) cout << endl;
        f = true;
        cout << catalan(n) << endl;
    }
    return 0;
}
