#include<bits/stdc++.h>

using namespace std;

int digitSum(int n);

int main()
{
    int t,n,i,gen,num10,digit;
    bool f ;
    //ofstream fcout("file.txt");
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        f = false ;
        num10 = log10(n)+1 ;
        num10 = num10*9 ;
        gen = n-num10 ;
        if(gen<0)
            gen = 0 ;
        for(i=gen;i<n;i++)
        {
            if(i+digitSum(i)==n)
            {
                f = true ;
                break ;
            }
        }
        if(f)
            cout << i << endl ;
        else
            cout << 0 << endl;
    }
    return 0;
}

int digitSum(int n)
{
    int sum = 0 ;
    while(n)
    {
        sum += n%10 ;
        n /= 10 ;
    }
    return sum ;
}
