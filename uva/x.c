#include<stdio.h>
int main()
{
	int a,b,c,d,l;
	int count,i,z;
	while(1)
{
	count=0;	scanf("%d%d%d%d%d",&a,&b,&c,&d,&l);
	if(a==0&&b==0&& c==0&&d==0&&l==0)
	break;
	for(i=0;i<=l;i++){
	z=a*i*i+b*i+c;
	if(z%d==0)
     count++;
	}
		printf("%d\n", count);
	}
	return 0;
}