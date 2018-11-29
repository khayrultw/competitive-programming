#include<bits/stdc++.h>

using namespace std ;

int divisor[1000001],flag[1000001];
void FindDivisor() ;

int main()
{
    fill(divisor,divisor+1000001,1);
    //clock_t tt = clock();
    FindDivisor();
    //cout << (clock()-tt)/CLOCKS_PER_SEC << endl;
    int t,n,i,max,num;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        cout << flag[n] << endl;
    }
}

void FindDivisor()
{
    for(int i=2 ; i<=1000000;i++)
    {
        for(int j=i ; j<=1000000;j+=i)
        {
            divisor[j]++ ;
        }
    }
    flag[1] = 1 ;
    for(int i=2;i<=1000000;i++)
    {
        if(divisor[i]>divisor[flag[i-1]])
            flag[i] = i;
        else
            flag[i] = flag[i-1] ;
    }
}
