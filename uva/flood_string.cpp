#include<bits/stdc++.h>

using namespace std;

int main()
{
    char sub1[5001],sub2[5001],str[5004],st[100],tmp[100],ch;
    int n,m,t,i,x,y,z,len;
    cin >> t ;
    while( t-- )
    {
        cin >> n >> m ;
        cin >> str;
        cin.ignore();
        for(i=0;i<m;i++)
        {

            gets(st);
            if(sscanf(st,"%s %d %d %d",tmp,&x,&y,&z)==4)
            {
                int k=0;
                for(int j=x-1;j<x+z;j++)
                    sub1[k++]=str[j];
                sub1[k]='\0';
                k=0;
                for(int j=y-1;j<y+z;j++)
                    sub2[k++]=str[j];
                sub2[k]='\0';
                if(strcmp(sub1,sub2)==0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if(sscanf(st,"%s %d %d",tmp,&x,&y)==3)
            {
                if(strcmp(tmp,"rev")==0)
                {
                    int j=x-1,k=y-1;
                    while(j<=k)
                    {
                        ch = str[j] ;
                        str[j] = str[k] ;
                        str[k] = ch ;
                        j++;
                        k--;
                    }
                }
                if(strcmp(tmp,"pal")==0)
                {
                    int k=0;
                    for(int j=x-1;j<y;j++)
                    sub1[k++] = str[j] ;

                    sub1[k] = '\0' ;
                    for(int j=0;strlen(sub1);j++)
                        sub2[j] = sub1[y-j-1] ;
                    sub2[strlen(sub1)]='\0' ;
                    if(strcmp(sub1,sub2)==0)
                        cout << "YES" << endl;
                    else
                        cout << "NO" << endl;
                }
            }
            else if(sscanf(st,"%s %d %c",tmp,&x,&ch)==3)
            {
                int k=0;
                for(int j=0;str[j]!='\0';j++)
                {
                    if(j==x)
                        sub1[k++]=ch;
                    sub1[k++]=str[j];
                }
                sub1[k]='\0';
                strcpy(str,sub1);
            }
            else if(sscanf(st,"%s %d",tmp,&x)==2)
            {
                cout << str[x-1] << endl;
            }
        }
        return 0;
    }
}
