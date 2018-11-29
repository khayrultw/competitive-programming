#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row, col;
    string str[101];
    int rc[101][101], cc[101][101];
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        cin >> str[i];
    }
    for(int i = 0; i < row; i++)
    {
        int k = 0, coun = 0;
        for(int j = 0; j < row; j++){
            if(str[i][j] == '#'){
                for(k; k < j; k++)
                    rc[i][k] = coun;
                coun = 0;
                k = j+1;
            }
            else if(j==row-1 && str[i][j] == '.')
            {
                for(k; k < row; k++)
                    rc[i][k] = coun+1;
                coun = 0;
                k = j+1;
            }
            else coun++;
        }
        k = 0, coun = 0;
        for(int j = 0; j < row; j++){
            if(str[j][i] == '#'){
                for(k; k < j; k++)
                    cc[k][i] = coun;
                coun = 0;
                k = j+1;
            }
            else if(j==row-1  && str[i][j] == '.')
            {
                for(k; k < row; k++)
                    cc[k][i] = coun+1;
                coun = 0;
                k = j+1;
            }
            else coun++;
        }
    }
    int ansr, ansc, mx = 0, r, c;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
        {
            r = c = 0;
            if(rc[i][j]==col) r = 1;
            else if(rc[i][j]>col)
            {
                r = 1;
                if(j && rc[i][j-1]=='.' && rc[i][j+1]=='.' && j != row-1)
                    r = 2;
            }
            if(cc[i][j]==col) c = 1;
            else if(cc[i][j]>col)
            {
                c = 1;
                if(i && str[i-1][j]=='.' && str[i+1][j]=='.' && i!=row-1)
                    c = 2;
            }
            if(mx < r+c)
            {
                mx = r+c;
                ansr = i+1;
                ansc = j+1;
               // cout << ansr << " " << ansc << " ";
                //cout << r << " " << c << " " << cc[i][j] << " ";

            }
        }
        //cout << endl;
    }
    cout << ansr << " " << ansc << endl;
    return 0;
}