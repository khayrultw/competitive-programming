#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,x,y;
    int t,cas=0;
    cin >> t ;
    while(++cas<=t)
    {
        cin >> c;
        a = sqrt(c);
        b = c-a*a;
        if(a&1)
        {
            x = 1;
            y = a;
            if(b>a+1)
            {
                y = x = a+1;
                b -= a+1;
                y -=b;
            }
            else if(b>0)
            {
                y++;
                b--;
                x+=b;
            }
        }
        else
        {
            y = 1;
            x = a;
            if(b>a+1)
            {
                y = x = a+1;
                b -= a+1;
                x -=b;
            }
            else if(b>0)
            {
                x++;
                b--;
                y+=b;
            }
        }
        cout << "Case " << cas << ": " << x << " " << y << endl;
    }
    return 0;
}
