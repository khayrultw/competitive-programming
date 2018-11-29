#include<bits/stdc++.h>

using namespace std ;

bool isPrime(int n) ;
int prim[34000];
void PrimeGenerate() ;

int main()
{
    //ofstream fcout("file.txt");
    int a,b,low,k,i,d,count;
    vector<int> detP;
    prim[0] = 2 ; prim[1] = 3 ;prim[2] = 5 ; prim[3] = 7 ;
    PrimeGenerate();
    while(cin >> a >> b &&  (a!=0 || b!=0))
    {
        for(i=0;prim[i]<=b;i++)
        {
            if(prim[i]>=a)
            {
                k = i ;
                break;
            }
        }

        d = prim[k+1]-prim[k] ; count = 1 ;
        detP.push_back(prim[k]) ;

        for(i=k+2;prim[i]<=b;i++)
        {
           if(prim[i]-prim[i-1]==d)
           {
                    count++ ;
                    detP.push_back(prim[i-1]) ;
           }
           else if(count>=2)
           {
                    for(int j=0;j<count;j++)
                    {
                        cout << detP[j] << " " ;
                    }
                    detP.clear();
                    cout << prim[i-1] << endl;
                    detP.push_back(prim[i-1]) ;
                    count = 1 ;
                    d = prim[i]-prim[i-1] ;
            }
            else
            {

                detP.clear();
                detP.push_back(prim[i-1]) ;
                count = 1 ;
                d = prim[i]-prim[i-1] ;
            }
         }
         if(count>=2)
         {
                for(int j=0;j<count;j++)
                {
                    cout << detP[j] << " " ;
                }
                cout << prim[i-1] << endl;
         }
         detP.clear();
    }
    return 0;
}
bool isPrime(int n)
{
        if(n==2)
            return true ;
        for(int i=0; prim[i]<=sqrt(n);i++)
        {
            if(n%prim[i]==0)
                return false ;
        }
        return true ;
}

void PrimeGenerate()
{
    int k = 4, i ;
    for(i=11;i<=35000;i+=2)
    {
        if(isPrime(i))
            prim[k++] = i ;
    }
}

