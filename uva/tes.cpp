#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int check[5];
    int log[120];

    while(cin>>n)
    {

        check[0] = 1;
        check[1] = 2;
        for(int i = 0; i<n; i++)
        {

            cin>>log[i];
        }
        int flag = 0;
        for(int i = 0; i<n; i++)
        {
            int temp = 0;
            int pos;
            int val1,val2;
            for(int j = 0; j<2; j++)
            {

                val1 = check[0];
                val2 = check[1];
                if(log[i]==check[j])
                {
                    temp=1;

                }else pos = j;

            }
            if(temp==0)
            {
                flag=1;
                //cout<<"not "<<i<<endl;
                break;
            }
            else
            {

                if(val1!=1&&val2!=1)
                {
                    check[pos] = 1;
                }
                else if(val1!=2&&val2!=2)
                {
                    check[pos] = 2;
                }
                else if(val1!=3&&val2!=3)
                {
                    check[pos] = 3;
                }
            }
        }

        if(flag==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
