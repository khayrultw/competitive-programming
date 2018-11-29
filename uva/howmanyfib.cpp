#include<bits/stdc++.h>

using namespace std;

#define PHI (1+sqrt(5))/2
#define SHI (1-sqrt(5))/2

int binary(double fibo,int low,int high)
{
    if(low==high)
        return low;
    int mid = (low+high)/2;
    double fib = (pow(PHI,mid)-pow(SHI,mid))/sqrt(5);
    if(fib==fibo)
        return mid ;
    if(fib>fibo)
        return binary(fibo,low,mid);
    return binary(fibo,mid+1,high);
}

int main()
{
    double a,b;
    int low,high;
    while(cin >> a >> b)
    {
        low = binary(a,1,500);
        high = binary(b,1,500);
        double x = (pow(PHI,low)-pow(SHI,high))/sqrt(5) ;
        if(x<a)
            low++;
        x = (pow(PHI,low)-pow(SHI,high))/sqrt(5);
        if(x>b)
            high--;
        cout << high-low << endl;
    }
    return 0;
}
