#include<bits/stdc++.h>

using namespace std;

int main(){
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int sh = k*ceil(1.00*n/s);
    printf("%d\n", (int)ceil(1.0*sh/p));
    return 0;
}