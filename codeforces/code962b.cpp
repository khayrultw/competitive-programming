#include<bits/stdc++.h>

using namespace std;

int main()
{
    int si , x, y;
    cin >> si >> x >> y;
    string str;
    cin >> str;
    int a=0,b=0;
    for(int i = 0; i < si; i++)
    {
        if(str[i] == '*')
        {
            for(int j = 1; i+j < si; j++)
            {
                if(str[i+j] == '*')
                {
                    i = i+j-1;
                    break;
                }
                if(j&1)
                    a++;
                else
                    b++;
            }
        }
    }
    bool f = false;
    for(int i = 0; i < si; i++) 
    {
        if(str[i] == '*')
        {
            f = true;
            if((i)&1){
                a += (i+1)/2;
                b += (i)/2;
            }
            else
            {
                a += (i)/2;
                b += (i)/2;
            }
            
            break;
        }
    }
    if(!f)
    {
        if((si)&1){
                a += (si+1)/2;
                b += (si)/2;
        }
        else
        {
            a += (si)/2;
            b += (si)/2;
        }
    }
    int sum = 0;
    if(x < y)
        swap(x, y);
    sum += min(a, x);
    sum += min(b, y);
    cout << sum << endl;
    return 0;

}