#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t,i,arr[100],k;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        if(n==1)
        {
            cout << 1 << endl;
            continue;
        }
        k=0;
        for(i=9;i>1;)
        {
            if(n%i==0)
            {
                arr[k++]=i;
                n=n/i;
            }
            else i--;
        }
        if(n==1)
        {
            sort(arr,arr+k) ;
            for(i=0;i<k;i++)
                cout << arr[i] ;
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
