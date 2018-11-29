#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t,i;
    bool f ;
    string str[25] ;
    cin >> t ;
    while(t--)
    {
        bool f = false;
        for(i=0;i<20;i++)
        {
            cin >> str[i] ;
        }
         for(i=0;i<20;i++)
        {
            if(f)
                cout << " " ;
            if(str[i]=="cheater")
                cout << "charming" ;
            else if(str[i]=="programmer")
                cout << "man with love and life" ;
            else if(str[i]=="kala" && str[i+1]=="para" && str[i+2]=="na")
            {
                cout << "khela pare" ;
                i=i+2;
            }
            else if(str[i]=="appy" && str[i+1]=="nyc" && str[i+2]=="lagca")
            {
                cout << "vaiya you are very handsome" ;
                i+=2 ;
            }
            else
                cout << str[i] ;
            f = true;
        }
        cout << endl;
    }
    return 0;
}
