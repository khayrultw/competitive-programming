#include <iostream>

using namespace std;

int maxx(int a, int b){
    return (a>b)?a:b;
}

int dp[100000][20];

int tot = 0;

int find(const int *ptr, int n){
    for(int i = 0; i < tot; i++){
        if(dp[i][1] == n){
            bool f = true;
            for(int j = 0; j < n; j++){
                if(ptr[i] != dp[i][j+2])
                {
                    f = false;
                    break;
                }
            }
            if(f){
                return dp[i][0];
            }
        }
    }
    return -1;
}
int maxi(const int p[], const int n){
    if(n == 1)
        return p[0];

    int yyy = find(p, n);
    if(yyy != -1)
        return yyy;

    int sum = 0;
    int f;
    int ptr[n-1];
    for(int i = 1; i < n; i++)
        ptr[i-1] = p[i];

    int tmp = p[1]+maxi(ptr, n-1);
    if(tmp > sum){
        f = 0;
        sum = tmp;
    }

    for(int i = 1; i < n-1; i++){
        int ptr1[n-1];
        int k = 0;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            ptr1[k++] = p[j];
        }
        tmp = p[i-1]*p[i+1]+maxi(ptr1, n-1);
        if(tmp > sum){
            f = i;
            sum = tmp;
        }
    }

    int ptr2[n-1];
    for(int i = 0; i < n-1; i++)
        ptr2[i] = p[i];
    tmp = p[n-2]+maxi(ptr2, n-1);

    if(tmp > sum){
        f = n-1;
        sum = tmp;
     }
    // for(int i = 0; i < n; i++){
    //     cout << p[i] << " ";
    // }
    // cout << endl << f << " " << sum << endl;
    dp[tot][0] = sum;
    dp[tot][1] = n;

    for(int i = 0; i < n; i++)
        dp[tot][2+i] = p[i];
    tot++;
    cout << tot << endl;
    return sum;
}

int main(){
    for(int i = 0; i < 10000; i++)
        for(int j = 0; j < 100; j++)
            dp[i][j] = -1;
    
    int arr[] = {2, 3, 2, 1, 2, 3, 4, 3, 4, 2, 1};
    cout << maxi(arr, 9) << " " << tot << endl;

}