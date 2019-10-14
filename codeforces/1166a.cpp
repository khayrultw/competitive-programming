#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;;
    int fr[26];
    memset(fr, 0, sizeof(fr));
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        fr[str[0]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        int a, b;
        a = b = fr[i]/2;
        if(fr[i]&1)
            a++;
        ans += (a*(a-1))/2;
        ans += (b*(b-1))/2;
    }
    cout << ans << endl;
    return 0;
}