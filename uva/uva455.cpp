#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    string s;
    cin >> t;
    while(t--){

        cin >> s;
        int i, j;
        for(i = 1; i <= s.size(); i++){

            for(j = 0; j < s.size(); j++)
                if(s[j]!=s[j%i]) break;

            if(j==s.size()){

                int a, b;
                a = i;
                b = j;
                while(a--){

                    b--;
                    if(s[a]!=s[b]) break;
                }
                if(a ==-1) break;

            }
        }
        cout << min(i, (int)s.size()) << endl;
        if(t) cout << endl;
    }
    return 0;
}
