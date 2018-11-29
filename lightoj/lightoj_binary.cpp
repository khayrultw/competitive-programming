#include<bits/stdc++.h>

using namespace std;

struct node
{
	int left, right, sum;
};

node tree[3*100001];

void maketree(int,int, int);
void update(int,int,int);
int getSum(int,int,int);

int main()
{
	string s;
	char ch;
	int q, a, b, cas = 0, t;
	cin >> t;
	while(++cas<=t)
	{
		cin >> s;
		maketree(1,1,s.size());
		scanf("%d",&q);
		printf("Case %d:\n",cas);
		for(int i=0;i<q;i++)
		{
			getchar();
			scanf("%c",&ch);
			if(ch=='I')
			{
				scanf("%d%d", &a, &b);
				//cout << "NO" << endl;
				update(1, a, b);
			}
			else
			{
				scanf("%d", &a);
				int tmp = getSum(1,0,a);
				//cout << tmp << endl;
				if(tmp&1)
				{
					if(s[a-1] == '0')
						printf("1\n");
					else
						printf("0\n");
				}
				else
					printf("%c\n", s[a-1]);
			}
		}
	}
	return 0;
}

void maketree(int at,int i, int j)
{
	tree[at].sum = 0;
	if(i==j)
	{
		tree[at].left = tree[at].right = i;
		return ;
	}
	tree[at].left = i;
	tree[at].right = j;
	int mid = (i+j)/2;
	maketree(2*at,i,mid);
	maketree(2*at+1,mid+1,j);
}

void update(int at, int i, int j)
{
	if(i>tree[at].right || j<tree[at].left)
		return ;
	if(i<=tree[at].left && tree[at].right<=j)
	{
		tree[at].sum++;
		return ;
	}
	update(2*at,i,j);
	update(2*at+1,i,j);
}

int getSum(int at, int valat, int indx)
{
	//cout << at << " " << tree[at].sum  << " " << valat << endl;
	if(indx<=tree[at].left && indx>=tree[at].right)
	{
		tree[at].sum += valat;
		return tree[at].sum;
	}
	if(indx<tree[at].left || indx>tree[at].right)
	{
		tree[at].sum += valat;
		return -1;
	}
	int tmp = tree[at].sum+valat;
	tree[at].sum = 0;
	int a,b;
	a = getSum(2*at,tmp,indx);
	b = getSum(2*at+1,tmp,indx);
	return max(a,b);
}


