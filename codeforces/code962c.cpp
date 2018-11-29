#include<bits/stdc++.h>

using namespace std;

long long power(int n)
{
    long long sum = 1;
    while(n--)
    {
        sum *= 10;
    }
    return sum;
}

int findM(long long x, int lev)
{
    cout << x << endl;
    lev++;
    int mn = 100000, k = log10(x)+1;
    long long n, dv, m, tmp;
    for(int i = 1; i <= k; i++)
    {
        m = power(i);
        n = x / m;
        tmp = sqrt(n);
        if(tmp * tmp == n)
        {
            return lev;
        }
        dv = x % m;
        dv = dv % (m/10);
        int dig = log10(n)+1;
        tmp = n+dv*power(dig);
        cout << n << " " << i<< " " << dv  << endl;
        mn = min(mn, findM(tmp, lev)) ;

    }
    return mn;
}
int main()
{
    int a = 10;
    int b = 10;
    cout << min(a,b);
    long long n;
    cin >> n;
    n = findM(n, 0);
    cout << n <<" kkk"<< endl;
    
}