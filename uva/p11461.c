#include<stdio.h>
#include<math.h>
int fun(int a,int b);
int main()
{
	int a,b,count;
	while(1)
	{
		count=0;
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)
		break;
		if(a<b)
		    count=fun(a,b);
		else
		    count=fun(b,a);
		    
		printf("%d\n",count);
	}
	return 0;
}
int fun(int a,int b)
{
   	int count,i,tmp;
   	tmp=a;
		a=sqrt(a);
		b=sqrt(b);
		if(tmp%a!=0)
		a++;
		for(i=a
		return b-a;
}