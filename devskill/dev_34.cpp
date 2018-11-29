#include<iostream>

using namespace std;

int main()
{
    int n,t,dig;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        dig = 0 ;
        while(n)
        {
           dig++;
           n=n/10;
        }
        cout << dig << endl;
    }
    return 0;
}
