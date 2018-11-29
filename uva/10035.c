#include<stdio.h>
int fun(int a,int b);
int main()
{
	int a,b,count;
	while(1)
	{
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)
	break;
	count=fun(a,b);
	if(count>1)
	printf("%d carry operations.\n",count);
	else if(count)
	printf("%d carry operation.\n",count);
	else
	printf("No carry operation.\n");
	}
	return 0;
}
int fun(int a,int b)
{
	int count=0,x,k=0;
		while(a!=0 || b!=0)
		{
			x=k+(a%10)+(b%10);
	     	if(x>=10){
		 	count++;
             k=1;
	     	}
            else
            k=0;
			a=a/10;
		    b=b/10;
		}
		return count;
}