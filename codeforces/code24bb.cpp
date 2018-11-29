#include<bits/stdc++.h>

using namespace std;
int indx;
long long find_max(long long ar[],long long a,long long b)
{
    long long max = ar[a];
    for(long long i=a;i<=b;i++)
    {
        if(max<ar[i]){
            max = ar[i];
            indx = i;
        }
    }
    return max;
}

long long find_min(long long ar[],long long a,long long b)
{
    long long min = ar[a];
    for(long long i=a;i<=b;i++)
    {
        if(min>ar[i]){
            min = ar[i];
            indx = i;
        }
    }
    return min;
}

int main()
{
    long long p,q,r,n,arr[100001],sum=0,tmp;
    cin >> n >> p >> q >> r;
    if(p>0)
    {
        tmp = find_max(arr,1,n-2);
        sum += p*tmp;

    }
    else if(p<)
}
