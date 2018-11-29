#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,n,k;
    while( cin >> n && n!=0 )
    {
        k = ceil(1.00*n/4);
        k = 4*k;
        printf("Printing order for %d pages:\n",n);
        for(int i=1; i<=n&&i<=k/2; i++)
        {
            printf("Sheet %d, ", (int)ceil(1.00*i/2));
            if(i&1)
            {
                printf("front: ");
                a = k-i+1;
                if(a>n)
                    printf("Blank, ");
                else
                    printf("%d, ",a);
                printf("%d\n",i);
            }
            else
            {
                printf("back : %d, ",i);
                b = k-i+1;
                if(b>n)
                    printf("Blank\n");
                else
                    printf("%d\n",b);
            }
        }
    }
    return 0;
}
