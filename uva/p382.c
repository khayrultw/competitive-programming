#include<stdio.h>
int main()
{
	int n[101],i,j,sum,k=0;
	
	for(i=1;i<99;i++)
	{
		scanf("%d",&n[i]);
		k++;
		if(n[i]==0)
		break;
	}
    printf("PERFECTION OUTPUT\n");
	for(j=1;j<k;j++)
	{
		sum=1;
	    for(i=2;i<=n[j]/2;i++)
		{
			if(n[j]%i==0)
			sum+=i;
		}
		if(n[j]==sum)
		printf("%5d  PERFECT\n",n[j]);
		else if(sum<n[j])
		printf("%5d  DEFICIENT\n",n[j]);
		else
		printf("%5d  ABUNDANT\n",n[j]);
	}
	printf("END OF OUTPUT\n");
	return 0;
}