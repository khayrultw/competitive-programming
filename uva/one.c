#include<stdio.h>
#include<string.h>
int test(char str1[],char strr2[]);
int main()
{
	int n,z;
	char str[11];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		if(str[0]=='o'&&strlen(str)==2);
		{
		    z=test("one",str);
		    if(z)
		    printf("1\n");
		}
		if(str[0]=='t'&&strlen(str)==2)
		{
			z=test("two",str);
			if(z)
			printf("2\n");
		}
		if(str[0]=='t'&&strlen(str)==5)
		{
			z=test("three",str);
			if(z)
			printf("3\n");
		}
	}
	return 0;
}
int test(char str1[],char strr2[])
{
	int i,count=0,len;
	len=strlen(str1);
	for(i=0;str1[i]!='0';i++){
		if(str1[i]==strr2[i])
		count++;
	}
	if(count>=len-1)
	return 1;
	return 0;
}
		