#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string str;
        cin >> n;
        cin >> str;
        while(str[0] != '8' && str != "")
            str.erase(str.begin());
        if(str.size() > 10)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
        
    }
   
}