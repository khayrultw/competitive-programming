#include<iostream>

using namespace std;

int main()
{
        int t,cas=0,a,b,c;
        cin >> t ;
        while( ++cas<=t )
        {
            cin >> a >> b >> c ;
            if(!(a+b>c && a+c>b && b+c>a))
                cout <<"Case " << cas << ": Invalid" << endl;
            else if(a==b && b==c)
                cout <<"Case " << cas <<  ": Equilateral" << endl;
            else if(a==b || a==c || b==c)
                cout <<"Case " << cas << ": Isosceles" << endl;
            else
                cout <<"Case " << cas << ": Scalene" << endl;
        }
        return 0;
}
