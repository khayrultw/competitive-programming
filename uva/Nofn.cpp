#include<bits/stdc++.h>

using namespace std ;

int divisor(int n);
void ArrayGen();
int lst[65000] = {} ;
int flag[1000000];

int main()
{
    int t,a,b,i=0;
    ArrayGen();
    cin >> t ;
    while(++i<=t)
    {
        cin >> a >> b ;
        a = flag[a] ;
        b = flag[b] ;
        cout << "Case " << i << ": " << b-a+1 << endl;
    }

}

void ArrayGen()
{
    lst[0]=1;lst[1]=2;
    int k=2;
    flag[1]=1;flag[2]=2;

    for(int i=2 ;i<=64750;i++)
    {
        lst[i]=lst[i-1]+divisor(lst[i-1]) ;

        for(int j=lst[i-1]+1;j<=lst[i];j++)
            flag[j] = flag[lst[i-1]] ;

        flag[lst[i]]++;
    }
}

int divisor(int n)
{
    int sum=2,i,root;
    root = sqrt(n);
    for(i=2;i<=root;i++)
    {
        if(n%i==0)
            sum+=2 ;
    }
    if(root*root==n)
        sum--;
    return sum ;
}
