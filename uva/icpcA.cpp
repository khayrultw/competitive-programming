#include<bits/stdc++.h>

using namespace std;

void binToDec(char s[], int dec[])
{
    int n = 0, i, j = 1 ;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            j++;
            continue;
        }
        dec[j] = dec[j]<<1;
        if(s[i]=='1')
            dec[j] = dec[j]|1;
    }
}

int main()
{
    int adec, bdec, cdec, ddec, i, t, cas = 0,dec[5];
    char bin[200];
    scanf("%d", &t);
    while( ++cas<=t )
    {
        dec[1] = dec[2] = dec[3] = dec[4] = 0;
        scanf("%d.%d.%d.%d", &adec, &bdec, &cdec, &ddec);
        scanf("%s", bin);
        binToDec(bin,dec);
        printf("%d %d %d %d",dec[1],dec[2],dec[3],dec[4]);
        if(adec==dec[1] && bdec==dec[2] && cdec==dec[3] && ddec==dec[4])
            printf("Case %d: Yes\n",cas);
        else
            printf("Case %d: No\n",cas);
    }
    return 0;
}
