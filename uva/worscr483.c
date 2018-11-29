#include<stdio.h>
#include<string.h>
#include<ctype.h>
int test(char ch);
int main()
{
    int len,i,j,k,t;
    char wor[1000000],w[1000],ch;
    while(gets(wor))
    {
        k=0;
        j=-1;
        len=strlen(wor);
        for(i=0;i<len;i++)
        {
           if(isalpha(wor[i]))
           w[++j]=wor[i];

           else
           {
               w[++j]='\0';
               t=test(w[0]);
                if(t&&j!=0)
                    printf("%say",w);
                else if(j!=0)
                {
                    printf("%s%cay",w+1,w[0]);
                }
                printf("%c",wor[i]);
                j=-1;
                continue;
           }

        }
        printf("\n");
    }
    return 0;
}
int test(char ch)
{
    char vowel[]="AEIOUaeiou";
    int i,k=0;
    for(i=0;i<10;i++)
    {
        if(ch==vowel[i])
        {
            k=1;
            break;
        }
    }
    return k;
}
