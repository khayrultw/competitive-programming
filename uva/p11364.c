#include<stdio.h>
int max(int n,int x[]);
int min(int n, int x[]);
int main()
{
	int t,x[100];
	int i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		i=0;
		for(i=0;i<n;i++)
		scanf("%d",&x[i]);
		printf("%d\n",2*(max(n,x)-min(n,x)));
	}
	return 0;
}
int max(int n,int x[])
{
	int j,mx=x[0];
	for(j=0;j<n;j++)
	if(x[j]>mx)
	mx=x[j];
	return mx;
}
int min(int n,int x[])
{
	int k,mn=x[0];
	for(k=0;k<n;k++)
	if(mn>x[k])
	mn=x[k];
	return mn;
}
		