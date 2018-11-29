#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3,ma;
    while(cin>>n1>>n2>>n3)
    {
        if(n1>n2)
        {
            ma=n1;
            n1=n2;
            n2=ma;
        }
        if(n1>n3)
        {
            ma=n1;
            n1=n3;
            n3=ma;
        }
        if(n2>n3)
        {
            ma=n2;
            n2=n3;
            n3=ma;
        }
        cout<<n1+n2*2<<endl;
    }
    return 0;
}
