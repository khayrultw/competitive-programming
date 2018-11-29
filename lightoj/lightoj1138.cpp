#include<bits/stdc++.h>

using namespace std;

int numOfZero(int n){

    int div = 5, sum = 0;
    while(n/div){

        sum += n/div;
        div *= 5;
    }
    return sum;
}

int binary(int l, int r, int zero){

    if(r>l){

        int mid = (l+r)/2;
        int z = numOfZero(mid);
        if(z>=zero)
            return binary(l, mid, zero);
        else
            return binary(mid+1, r, zero);
    }
    return l;
}

int main(){

    int t, cas = 0, n;
    scanf("%d", &t);
    while(++cas <= t){

        scanf("%d", &n);
        int z = binary(1, 500000000, n);
        if(numOfZero(z) == n)
            printf("Case %d: %d\n", cas, z);
        else
            printf("Case %d: impossible\n", cas);
    }
    return 0;
}
