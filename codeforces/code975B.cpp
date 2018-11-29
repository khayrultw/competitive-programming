#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a[14], b[14], give, mx = 0, rem, sum;
    for(int i = 0; i < 14; i++)
        cin >> a[i];
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 14; j++)
            b[j] = a[j];
        give = b[i] / 14;
        rem = b[i]%14;
        b[i] = 0;
       // cout << rem << endl;
        int j = i+1;
        while(rem--){
            if(j == 14)
                j = 0;
            b[j++]++;
        }
        sum = 0;
        for(j = 0; j < 14; j++){
            if((give+b[j])%2==0){
                sum += give+b[j];
                //cout << b[j]  << " ";
            }
        }
        //cout <<  sum << endl;   
        if(sum > mx)
            mx = sum;
    }
    cout << mx << endl;
    return 0;
}