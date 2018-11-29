#include<stdio.h>
#include<string.h>
int main()
{
	char S[10];
	int cas=0;
	
	while(scanf("%s",S)&&strcmp(S,"*")!=0)
	{
		if(strcmp("Hajj",S)==0)
		printf("Case %d: Hajj_e_Akbar\n",++cas);
		else if(strcmp("Umra",S)==0)
		printf("Case %d: Hajj_e_Asghar\n",++cas);
	}
	return 0;
}