#include<bits/stdc++.h>

using namespace std;

struct node
{
    int left,right,val;
    node()
    {
        val = -1;
    }
};

node tree[101];
void maketree(int nod,int i,int j)
{
    tree[nod].left = i;
    tree[nod].right = j;
    if(i==j)
        return ;
    int mid = (i+j)/2;
    maketree(2*nod,i,mid);
    maketree(2*nod+1,mid+1,j);
}

void updatetree(int nod,int i,int j,int v)
{
    if(tree[nod].left>j || tree[nod].right<i)
        return ;
    if(tree[nod].left>=i && tree[nod].right<=j)
        tree[nod].val = v;
    else
    {
        int mid = (i+j)/2;
        updatetree(nod*2,i,mid,v);
        updatetree(2*nod+1,mid+1,j,v);
    }
}

void finalup(int n)
{
    int a,b;
    a = tree[2*n].val;
    b = tree[2*n+1].val;
    if(a==-1)
    {
        tree[2*n].val = tree[n].val;
        finalup(2*n);
    }
    else if(b==-1)
    {
        tree[2*n+1].val = tree[n].val;
        finalup(2*n+1);
    }
}

int main()
{
    int t,cas=0,n,q,a,b,c;
    scanf("%d",&t);
    while(++cas<=t)
    {
        scanf("%d%d",&n,&q);
        maketree(1,1,n);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            updatetree(1,a,b,c);
        }
        printf("%d",tree[1].val);
        for(int i=2;i<=n;i++)
            printf(" %d",tree[i].val);
        cout << endl;
        finalup(1);
        printf("%d",tree[1].val);
        for(int i=2;i<=n;i++)
            printf(" %d",tree[i].val);
        cout << endl;
    }
    return 0;
}
