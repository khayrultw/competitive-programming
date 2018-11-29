#include<stdio.h>
int rec(int n);
int main()
{
	int i,j,max,tmp,k;
	while(scanf("%d%d",&i,&j)!=EOF)
	{
		max=0;
		for(k=i;k<=j;k++)
		{
	 	   tmp=rec(k);
	        if(tmp>max)
	        max=tmp;
		}
		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}
int rec(int n)
{
	if(n%2==0)
	return 1+rec(n/2);
	return 1+rec(3*n+1);
}