#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int t,i,sum=0;
	char str[15],num[7];
	scanf("%d",&t);
    getchar();
    while(t--)
	{
		gets(str);
		
		if(str[0]=='d')
		{
			i=7;
			while(str[i]!='\0')
			{
				num[i-7]=str[i];
				i++;
			}
			num[i-7]='\0';
			sum+=atoi(num);
		}
		if(str[0]=='r')
		printf("%d\n",sum);
	}
	return 0;
}
			
		