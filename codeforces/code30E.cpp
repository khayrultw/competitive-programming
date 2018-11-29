#include<bits/stdc++.h>

using namespace std;

struct nod
{
    int val,ind;
};

bool operator<(const nod a,const nod b)
{
    return a.val>b.val;
}

int main()
{
    priority_queue<nod> pq;
    nod tmp;
    int n,ar[300001];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
        tmp.val = ar[i];
        tmp.ind = i;
        pq.push(tmp);
    }
    int indx,sum=0;
    for(int i=1;i<=n/2;i++)
    {
        tmp = pq.top();
        int max_val = tmp.val;
        pq.pop();
        indx = tmp.ind;
        for(int j=tmp.ind+1;j<=n;j++)
        {
            if(max_val<ar[j])
            {
                max_val = ar[j] ;
                indx = j;
            }
        }
        sum += max_val-tmp.val;
        ar[indx] = ar[tmp.ind] = 0;
    }
    printf("%d\n",sum);
    return 0;
}
