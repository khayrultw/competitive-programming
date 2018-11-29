#include<stdio.h>
float pi=3.14159;
int main()
{
	float R;
	while(scanf("%f",&R)!=EOF)
	{
		printf("A=%.4f\n",pi*R*R);
	}
	return 0;
}