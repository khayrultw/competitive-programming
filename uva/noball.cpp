#include<iostream>

using namespace std ;

int main()
{
    int i, j, t, cas = 0, k ;
    bool left,right ;
    char ball[6][6] ;
    cin >> t ;

    while( ++cas <= t )
    {
        for(i = 0; i < 5 ; i++ )
        {
            for(j = 0; j < 5; j++)
            {
                cin >> ball[i][j] ;
            }
        }
        k = 0 ;
        right = false ;
        left = true ;
        for(i = 0; i < 5 ; i++ )
        {
            for(j = 0; j < 5; j++)
            {
                if(ball[i][j] == '>')
                {
                    k = 1 ;
                    left = false ;
                    continue ;
                }
                if(ball[i][j] == '<')
                {
                    k = 2 ;
                    continue ;
                }
                if( k == 1 && ball[i][j] == '|')
                {
                    right = true ;
                    break ;
                }
                if( k == 2 && ball[i][j] == '|')
                {
                    left = false ;
                    break ;
                }
            }
            if(k)
                break ;
        }
        if(!right && !left)
            cout << "Case " << cas << ": " << "No Ball" << endl ;
        else
             cout << "Case " << cas << ": " << "Thik Ball" << endl ;
    }
    return 0;
}
