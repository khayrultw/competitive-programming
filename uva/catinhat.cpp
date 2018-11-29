#include<bits/stdc++.h>

using namespace std;

int x,y;

int binary(int low,int high)
{
    int mid = (low+high)/2;
    double a,b;
    a = log(x)/log(mid+1);
    b = log(y)/log(mid);
    cout << mid << " " << a << " " << b << endl;
    if(low>mid)
        return 0;
    if(a==b)
        return mid;
    if(a>b)
        return binary(low,mid-1);
    return binary(mid+1,high);
}

int poww(int n,int p)
{
    if(p==0)
        return 1;
    return n*(poww(n,p-1));
}
int main()
{
    int cat,dep,a,b;
    while( scanf("%d%d",&x,&y))
    {
        cat = binary(1,1000);
        dep = log(y)/log(cat);
        a=0;
        b=x;
        for(int i=0;i<dep;i++)
            a+=poww(cat,i);
        for(int i=1;i<=dep;i++)
        {
            b += poww(dep,i)*x/(dep+1);
            x = x/(dep+1);
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
