#include<bits/stdc++.h>

using namespace std;


int main(){

    int t, cas=0, n, q, tmp, a,b;
    vector<int> vec;
    scanf("%d", &t);
    while( ++cas <= t){
        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            vec.push_back(tmp);
        }
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i++){

            scanf("%d%d", &a, &b);
            printf("%d\n",upper_bound(vec.begin(), vec.end(), b)-lower_bound(vec.begin(), vec.end(), a));
        }
        vec.clear();
    }
    return 0;
}
