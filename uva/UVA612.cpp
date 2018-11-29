#include<bits/stdc++.h>

using namespace std;

struct Dna
{
        string s ;
        int unSort ;
};

int main()
{
        int t,n,m,i,v;
        bool f = false ;
        string tm;
        Dna obj[100] ;
        ofstream fcout("file.txt");
        cin >> t ;
        while( t-- )
        {
                cin >> m >> n ;
                for(i=0;i<n;i++)
                        cin >> obj[i].s ;
                for(i=0;i<n;i++)
                {
                        obj[i].unSort = 0 ;
                        for(int j=0;j<m-1;j++)
                        {
                                for(int k=j+1;k<m;k++)
                                {
                                        if(obj[i].s[j]>obj[i].s[k])
                                                obj[i].unSort++;
                                }
                        }
                }
                for(i=0;i<n-1;i++)
                {
                        for(int j=i+1;j<n;j++)
                        {
                                if(obj[i].unSort>obj[j].unSort)
                                {
                                       tm = obj[i].s ;
                                       obj[i].s = obj[j].s ;
                                       obj[j].s = tm ;
                                       v = obj[i].unSort ;
                                       obj[i].unSort = obj[j].unSort ;
                                       obj[j].unSort = v ;
                                }
                        }
                }
                if(f)
                    fcout << endl;
                f = true ;
                for(i=0;i<n;i++)
                        fcout << obj[i].s << " " << obj[i].unSort << endl;
        }
        return 0;
}

