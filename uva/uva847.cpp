#include<bits/stdc++.h>

using namespace std;

int canWin(int p, int x)
{
    if(p*9>=x)
        return 1;

    if(canWin(p*9,x)==1)
    return 0;

}

int main()
{
    int x;
    while( cin >> x )
    {
        if(canWin(1,x)==1)
            cout << "Stan wins." << endl;
        else
            cout << "Ollie wins." << endl;
    }
    return 0;
}
