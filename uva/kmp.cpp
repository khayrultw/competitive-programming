#include<bits/stdc++.h>

using namespace std;

char p[1000],sen[1000];
int pi[1000];

void prefixfuncion()
{
    int now;
    now = pi[0] = -1;
    for(int i=1;i<strlen(p);i++)
    {
        while(now!=-1 && p[now+1]!=p[i]){
            now = pi[now];
        }
        if(p[now+1]==p[i])
            pi[i] = ++now;
        else
            pi[i] = now = -1;

    }
}

int kmp()
{
    int now = -1;
    for(int i=0;i<strlen(sen);i++)
    {
        while(now!=-1 && p[now+1]!=sen[i])
            now = pi[now];
        if(p[now+1]==sen[i])
            ++now;
        else
            now = -1;
        if(now+1==strlen(p))
            return i;
    }
    return 0;
}
int main()
{
    while(scanf("%s",p))
    {
        prefixfuncion();
        scanf("%s",sen);
        int x = kmp();
        cout << x<< endl;
    }
}
