#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str, ans;
    cin >> n;
    cin >> str;
    if(str == "0"){
        cout << str << endl;
        return 0;
    }
    ans = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '0')
            ans += str[i];
    }
    ans = "1" + ans;
    cout << ans << endl;
    return 0;

}



