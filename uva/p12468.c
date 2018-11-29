#include<stdio.h>
int main()
{
	int a,b,x,max,min;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==-1&&b==-1)
		break;
		max=a>b?a:b;
		min=a<b?a:b;
		if(max-min<=50)
		printf("%d\n",max-min);
		else
		printf("%d\n",99-max+min+1);
	}
	return 0;
}