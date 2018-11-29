#include<bits/stdc++.h>

using namespace std ;

bool isPrime(int n) ;
int prim[1000000];
void PrimeGenerate() ;


int main()
{
        //ofstream fcout("file.txt");
        int n, a, b, i ;
        prim[0] = 2 ; prim[1] = 3 ;prim[2] = 5 ; prim[3] = 7 ;
        clock_t start = clock();
        PrimeGenerate();
        cout << (1.00*clock()-start)/CLOCKS_PER_SEC << endl;
        start = clock() ;
        siv();
        cout << (1.00*clock()-start)/CLOCKS_PER_SEC << endl;
        bool f ;
        while(cin >> n && n != 0 )
        {
                f = false ;
                for(i=0;prim[i]<=n/2;i++)
                {
                    a = prim[i] ;
                    b = n - a ;
                    if(isPrime(b))
                    {
                        f = true ;
                        break ;
                    }
                }
                if(f)
                    cout << n << ":\n" << a << "+" << b << endl;
                else
                    cout << n <<  ":\nNO WAY!" << endl;
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

