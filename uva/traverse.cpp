#include<bits/stdc++.h>

using namespace std;

class robot
{
    char dir[4] ;
    int x,y,drctn,rightx,righty,inx,iny;
    int lost[101][101];
public :
    robot();
    void init(int a,int b);
    void init(int a,int b,char c);
    bool update(char ints);
    void showxy();
    void showinxiny();
};

robot::robot()
{
    lost[101][101] = {} ;
    dir[0]='N';
    dir[1]='E';
    dir[2]='S';
    dir[3]='W';
}
void robot::init(int a, int b)
{
    rightx = a ;
    righty = b ;
}

void robot::init(int a, int b, char c)
{
    x = a;
    y = b;
    if(c=='N')
        drctn = 0 ;
    else if(c=='E')
        drctn = 1 ;
    else if(c=='S')
        drctn = 2 ;
    else drctn = 3 ;
}

bool robot::update(char ints)
{
    inx = x ;
    iny = y ;
    if(ints=='F')
    {
        if(drctn==0)
            y = y + 1 ;
        else if(drctn==1)
            x = x + 1 ;
        else if(drctn==2)
            y = y - 1 ;
        else
            x = x - 1 ;
        if(x>rightx || y > righty || x < 0 || y < 0)
        {
            if(lost[inx][iny]==1)
            {
                x = inx ;
                y = iny ;
                return true ;
            }
            return false ;
        }
    }
    else
    {
        if(ints == 'R')
        {
            drctn = (drctn+1)%4 ;
        }
        else
        {
            drctn -= 1 ;
            if(drctn<0)
                drctn+=4 ;
        }
    }
    return true ;
}

void robot::showxy()
{
    cout << x << " " << y << " " << dir[drctn] << endl;
}

void robot::showinxiny()
{
    cout << inx << " " << iny << " " << dir[drctn] << " LOST" << endl;
    lost[inx][iny] = 1 ;
}
int main()
{
    robot obj ;
    string s;
    int px,py,x,y,i;
    char pos ;
    bool f ;
    cin >> x >> y ;
    obj.init(x,y);
    while(cin >> px >> py >> pos)
    {
        obj.init(px,py,pos);
        cin >> s ;
        f = true ;
        for(i=0;i<s.size();i++)
        {
            if(!obj.update(s[i]))
            {
                f = false ;
                break ;
            }
        }
        if(!f)
            obj.showinxiny();
        else
            obj.showxy() ;
    }
    return 0;
}
