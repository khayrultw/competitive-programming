#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
class box
{
    double a, b, c ;
public:
    void set_box() ;
    double getbox() ;
} ;
void box :: set_box()
{
    cin>>a>>b>>c;
}
double box :: getbox()
{
   double d = a*a + b*b + c*c ;
   return sqrt(d);
}
int main()
{
    box bx ;
    int t ;
    cin >> t ;
    while( t-- )
    {
        bx.set_box() ;
        printf("%.2lf\n", bx.getbox()) ;
    }
    return 0;
}
