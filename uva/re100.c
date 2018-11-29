#include<stdio.h>
int func(int n);
main()
{
	int a,b,i,m,max;
	while(scanf("%d%d",&a,&b)!=EOF)
	{     
	      max=0;
      	for(i=a;i<=b;i++)
      	{
	        	m=func(i);
       	 	if(m>max)
	        	max=m;
      	}
	     printf("%d %d %d\n",a,b,max);
	}
	 return 0;
}
int func(int n)
{
	if(n==1)
	return 1;
	if(n%2==0)
	return 1+func(n/2);
	return 1+func(3*n+1);
}