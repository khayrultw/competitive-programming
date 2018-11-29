#include<bits/stdc++.h>

using namespace std;

struct nod
{
    int left,right,val,prev;
    nod()
    {
        val = prev = 0;
    }
};

string bin;
nod tree[500001];
int n;

void makeTree(int at,int i,int j)
{

    if(i==j)
    {
        tree[at].left = tree[at].right = i;
        return ;
    }
    tree[at].left = i;
    tree[at].right = j;
    int mid = (i+j)/2;
    makeTree(2*at,i,mid);
    makeTree(2*at+1,mid+1,j);
}

void update(int value,int at,int i,int j)
{
    //cout << tree[at].left << " " << tree[at].right << endl;
    if(tree[at].left>j || tree[at].right<i)
        return ;
    //cout << n << " up " << i << " " << j << " " << tree[1].val << endl;
    if(i==1 && j==n)
    {
        tree[1].val++;
            //cout << n << " up " << i << " " << j << " " << tree[1].val << endl;
        return ;
    }
    if(tree[at].left>=i && tree[at].right<=j)
    {
        tree[at].val += value - tree[at].prev + 1;
        tree[at].prev = value;
        cout << tree[at].val << " yes " << at << endl;

    }
    int mid = (i+j)/2;
    update(tree[at].val,2*at,i,mid);
    update(tree[at].val,2*at+1,mid+1,j);
}

int get(int at,int indx)
{
    if(tree[at].left==tree[at].right)
        return tree[at].val;
    int mid = (tree[at].left + tree[at].right)/2;
    if(indx<=mid)
    {
        if(tree[at].val>=tree[2*at].val)
            return tree[at].val;
        get(2*at,indx);
    }
    else
    {
        if(tree[at].val>=tree[2*at+1].val)
            return tree[at].val;
        get(2*at+1,indx);
    }
}
int main()
{
    int t,cas = 0,q,a,b,freq;
    char ch;
    scanf("%d",&t);
    while(++cas<=t)
    {
        cin >> bin;
        //cout << "Yesb" << endl;
        n = bin.size();
        makeTree(1,1,n);
        scanf("%d",&q);
       // cout << "Yesq" << endl;
        for(int i=1;i<=q;i++)
        {
            getchar();
            scanf("%c",&ch);
            cout << "Yes" << endl;
            if(ch == 'I')
            {
                scanf("%d%d",&a,&b);
                update(0,1,a,b);
                //cout << bin << endl;
            }
            else
            {
                scanf("%d",&a);
                freq = get(1,a);
                cout << tree[1].val << " freq " << freq << endl;
                if(freq&1)
                {
                    if(bin[a-1]=='0')
                        printf("1\n");
                    else
                        printf("0\n");

                }
                else
                    printf("%c\n",bin[a-1]);
            }
        }
    }
    return 0;
}
