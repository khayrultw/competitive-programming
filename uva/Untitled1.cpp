#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n);
void PrimeGenerate();
int prim[1000000] ;

int main()
{
    clock_t t = clock() ;
    PrimeGenerate();
    cout << (1.00*clock()-t)/CLOCKS_PER_SEC << endl;
    int low,high,i,sum,tmp;
    while(cin >> low >> high)
    {
        sum = 0 ;
        for(i=low;i<=high;i++)
        {
            tmp = i*i+i+41 ;
            if(isPrime(tmp))
            {
                sum++ ;
            }
        }
        double ans = 100.00*sum/(high-low+1) ;
        printf("%.2lf\n",ans);
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
    int k = 2, i ;
    prim[0]=2;prim[1]=3;
    for(i=5;i<=10000000;i+=2)
    {
        if(isPrime(i))
            prim[k++] = i ;
    }
}
