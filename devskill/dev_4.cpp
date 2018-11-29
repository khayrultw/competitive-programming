#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,y,sum,n[101],i,z;
    while(cin>>x>>y)
    {
        sum=0;
        for(i=0;i<y;i++)
            cin>>n[i];
        for(i=0;i<y;i++)
            sum+=n[i];
        z=ceil(1.00*x/sum);
        if(z==1)
        cout<<"Project will finish within "<<z<<" day."<<endl;
        else
        cout<<"Project will finish within "<<z<<" days."<<endl;

    }
    return 0;
}
