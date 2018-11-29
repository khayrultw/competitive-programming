#include<bits/stdc++.h>

using namespace std;

struct node
{
    int a,b;
    void set(int i,int j)
    {
        a = i;
        b = j;
    }
};

bool cmp(const node &x,const node &y)
{
    return abs(x.a-x.b)<abs(y.a-y.b) ;
}

int main()
{
    int n,arr[101];
    node ob[100];
    cin >> n ;+
    for(int i=0;i<2*n;i++)
        cin >> arr[i] ;
    sort(arr,arr+2*n);
    int k = 0;
    for(int i=0;i<2*n;i+=2)
    {
        ob[k++].set(arr[i],arr[i+1]);
    }
    sort(ob,ob+k,cmp);
    int sum=0;
    for(int i=0;i<n-1;i++)
        sum+=abs(ob[i].a-ob[i].b);
    cout << sum << endl;
    return 0;
}
