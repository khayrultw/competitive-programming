#include<stdio.h>
int main()
{
	int n,h[100],sum,av,i,k=0;
	while(++k)
	{
		sum=0;
		scanf("%d",&n);
		if(n==0)
		break;
		for(i=0;i<n;i++)
		scanf("%d",&h[i]);
		for(i=0;i<n;i++)
		 sum+=h[i];
		 av=sum/n;
		 sum=0;
		 printf("%dav",av);
		 for(i=0;i<n;i++){
            if(h[i]>av)
                sum+=h[i]-av;
		 }
		 printf("Set #%d\n",k);
		 printf("The minimum number of moves is %d.\n",sum);
		 printf("\n");
	}
	return 0;
}
