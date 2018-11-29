#include<stdio.h>
#include<math.h>
int main()
{
	int n,jol[3001],i,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<n;i++)
		scanf("%d",&jol[i]);
		for(i=1;i<n-1;i++)
		if(abs(jol[i]-jol[i+1])!=n-i)
		{
			break;
		}
		if(i==n-1)
		printf("Jolly\n");
		else
		printf("Not jolly\n");
	}
	return 0;
}