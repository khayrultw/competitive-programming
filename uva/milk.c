#include<stdio.h>
#include<math.h>
#define Pi acos(-1)
int main()
{
	int l,w,h,th;
	double z,tm;
	while(scanf("%d%d%d%d",&l,&w,&h,&th)!=EOF)
	{
	tm=l*acos(-1);
    if(h>tm)
	z=((l*w*h)-(0.5*l*w*tm));
    else
     z=0.5*h*w*(tm-h);
		printf("%.3lf mL\n",z);
	}
	return 0;
}