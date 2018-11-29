#include<stdio.h>
#include<math.h>
int main()
{
	 int k,tmp;
	 double d,u,v,x,z;
	tmp=0;
	scanf("%d",&k);
	while(++tmp<=k)
	{
	    scanf("%lf%lf%lf",&d,&u,&v);
	    if(v>u)
	    {
    	z=d*(1/sqrt(v*v-u*u)-1/v);
    	printf("Case %d: %.3lf\n",tmp,z);
	    }
    	else
    	printf("Case %d: can't determine\n", tmp);
	}
	return 0;
}
		