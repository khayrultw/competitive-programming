#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main()
{
    lint t, n;
    lint x, y, u, r, d, l;
    lint ansx, ansy, minx, miny, maxx, maxy;

    cin >> t;
    while(t--)
    {
        maxx = maxy = 100000;
        minx = miny = -100000;
        bool flag = true;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            cin >> u >> r >> d >> l;
            if(!u)
                minx = max(minx, x);
                
            if(!d)
                maxx = min(maxx, x);

            if(!l)
                miny = max(miny, y);
                
            if(!r)
                maxy = min(maxy, y);
        }

        //cout << minx << " " << miny << endl;
        //cout << maxx << " " << maxy << endl;
        if(minx > maxx || miny > maxy)
            cout << 0 << endl;
        else  
            cout << "1 " << minx << " " << miny << endl;
    }
    return 0;
}