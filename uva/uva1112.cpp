#include<bits/stdc++.h>

using namespace std;

typedef long long llng;
typedef map<int,int> MPI;
typedef map<int,int> :: iterator MIT;
typedef vector<int> VECI;
typedef priority_queue<int> PQI;

#define PI acos(-1.0)
#define F first
#define S second
#define forip(a,n) for(int i = a; i<=n; i++)
#define forin(a,n) for(int i = n; i>=a; i--)
#define forjp(a,n) for(int j = a; j<=n; j++)
#define _ << " " <<
#define PB push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

int arr[100001];

void updatePlus(llng ind,llng val,llng n)
{
    if(ind>n)
        return ;
    arr[ind] += val;
    ind = ind + (ind & (-ind));
    updatePlus(ind,val,n);
}

void updateMinus(llng ind,llng val,llng n)
{
    if(ind>n)
        return ;
    arr[ind] = arr[ind] - val;
    ind = ind + (ind & (-ind));
    updateMinus(ind,val,n);
}

llng sum(llng ind)
{
    if(ind==0)
        return 0;
    return arr[ind]+sum(ind-(ind&(-ind)));
}

int main()
{
    llng n,q,num[100001],a,b,c,t,cas=0;
    cin >> t;
    while(++cas<=t)
    {
        printf("Case %lld:\n",cas);
        memset(arr,0,sizeof(arr));
        scanf("%lld%lld",&n,&q);
        forip(1,n)
        {
            scanf("%lld",&num[i]);
            updatePlus(i,num[i],n);
        }
        forip(1,q)
        {
            scanf("%lld",&a);
            if(a==1)
            {
                scanf("%lld",&b);
                printf("%lld\n",num[b+1]);
                updateMinus(b+1,num[b+1],n);
                num[b+1] = 0;
            }
            else if(a==2)
            {
                scanf("%lld%lld",&b,&c);
                num[b+1] += c;
                updatePlus(b+1,c,n);
            }
            else
            {
                scanf("%lld%lld",&b,&c);
                printf("%lld\n",sum(c+1)-sum(b));
            }
        }
    }
    return 0;
}
