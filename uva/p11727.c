#include<stdio.h>
int main()
{
	int a,b,c,z;
	int T,tmp;
	scanf("%d",&T);
	tmp=0;
	while(++tmp<=T)
	{
		scanf("%d%d%d",&a,&b,&c);
		if((a>b&&a<c)||(a<b&&a>c))
		z=a;
		else if((b>a&&b<c)||(b<a&&b>c))
		z=b;
		else
		z=c;
		printf("Case %d: %d\n",tmp,z);
	}
	return 0;
}
	