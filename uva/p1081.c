#include<stdio.h>
int main()
{
	int s,d,x,y,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&s,&d);
		if((s>=d)&&((s+d)%2==0)){
		    x=(s+d)/2;
		    y=s-x;
		    printf("%d %d\n",x,y);
		}
		else
		printf("imposible\n");
	}
	return 0;
}