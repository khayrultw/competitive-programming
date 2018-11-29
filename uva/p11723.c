#include<stdio.h>
int main()
{
	int r,n,d,t=0,k,i;
	while(t++<=10002)
	{
		k=1;
		scanf("%d%d",&r,&n);
		if((r==0)&&(n==0))
		break;
	    for(d=0;d<=26;d++)
		{
   		 	if((n+n*d)>=r)
			{
			    printf("Case %d: %d\n",t,d);
			    k=0;
			    break;
			}
		}
		if(k)
    	printf("Case %d: imposible\n",t);
	}
	return 0;
}