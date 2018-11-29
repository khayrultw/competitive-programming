#include<stdio.h>
#include<math.h>
int main()
{
	int n,tmp,i=0;
	while(++i)
	{
		scanf("%d",&n);
		if(i<0)
		break;
		tmp=ceil(log10(n)/log10(2));
		printf("Case %d: %d\n",i,tmp);
	}
	return 0;
}
		