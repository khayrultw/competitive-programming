#include<bits/stdc++.h>

using namespace std;
long long indx;

long long find_max(long long arr[], long long a,long long b)
{
    long long max = arr[a];
    for(long long i=a;i<=b;i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
            indx = i;
        }
    }
    return max;
}

long long find_min(long long arr[],long long a,long long b)
{
    long long min = arr[a];
    for(long long i=a;i<=b;i++)
    {
        if(min>arr[i])
        {
            min = arr[i];
            indx = i;
        }
    }
    return min;
}

int main()
{
     long long p,q,r,a,b,c,n,arr[100001],tmp,x;
     cin >> n >> p >> q >> r;
     for(long long i=1;i<=n;i++)
     {
            scanf("%I64d",&arr[i]);
     }
     indx = 1;
     a=b=c=0;
     if(p>0)
     a =  find_max(arr,indx,n);
     if(p<0)
     a = find_min(arr,indx,n);
     if(q>0)
     b =  find_max(arr,indx,n);
     if(q<0)
        b = find_min(arr,indx,n);
     if(r>0)
     c =  find_max(arr,indx,n);
     if(r<0)
        c = find_min(arr,indx,n);
     tmp = a*p+b*q+c*r;
     //cout << a << " " << b << " " << c << endl;

     indx = 1;
     a=b=c=0;
     if(q>0)
     b = find_max(arr,indx,n);
     if(q<0)
        b = find_min(arr,indx,n);
     long long y = indx;
     if(p>0)
     a =  find_max(arr,1,indx);
     if(p<0)
        a = find_min(arr,1,indx);
    if(r>0)
     c =  find_max(arr,y,n);
     if(r<0)
        c = find_min(arr,y,n);
     x = a*p+b*q+c*r;
     //cout << a << " " << b << " " << c << endl;

     if(tmp < x )
        tmp = x;
    indx = 1;
    a=b=c=0;
    if(r<0)
        c = find_max(arr,indx,n);
     if(r<0)
        c = find_min(arr,indx,n);
     if(q>0)
     b = find_max(arr,1,indx);
     if(q<0)
        b = find_min(arr,1,indx);
    if(p>0)
     a =  find_max(arr,1,indx);
     if(p<0)
        a = find_min(arr,1,indx);
     x = a*p+b*q+c*r;
     //cout << a << " " << b << " " <<c << endl;
    if(tmp < x )
        tmp = x;
    cout << tmp << endl;
    return 0;
}
