#include<bits/stdc++.h>

using namespace std;


bool finds(char str1[],char str2[],int len2)
{
    char st[1000001];
    strcpy(st,str1);
    *(st+len2) = '\0';
    if(strcmp(st,str2)==0)
        return true;
    return false ;
}
int main()
{
    char str1[1000001],str2[1000001];
    int t,cas=0,len1,len2,sum;
    cin >> t ;
    while( ++cas<=t )
    {
        scanf("%s%s",str1,str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        sum=0;
        for(int i=0;i<=(len1-len2);i++)
        {
            if(finds(&str1[i],str2,len2))
                sum++;
        }
        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
