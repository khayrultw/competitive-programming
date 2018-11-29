#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> n;
    cin >> str;
    for(int i = 0; i < n-1; i++)
    {
        if(str[i]!='?' && str[i] == str[i+1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}