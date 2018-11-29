#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b);

long long A[200001],B[200001] ;

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&A[i]) ;
    for(i=0;i<n;i++)
        scanf("%lld",&B[i]) ;
    sort(A,A+n,cmp);
    for(i=0;i<n-1;i++)
        printf("%lld ",A[i]) ;
    printf("%lld",A[n-1]);
    return 0;
}

bool cmp(int a,int b)
{
    long long w,x,y,z;
    x = A[a]-B[a];
    w = A[b]-B[b];
    y = A[b]-B[a];
    z = A[a]-B[b] ;
  return z>x || y>w;
}
