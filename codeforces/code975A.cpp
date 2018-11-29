#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string str, tmp;
    cin >> n;
    set<char> setch;
    set<char> :: iterator it;
    set<string> setstr;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            setch.insert(str[j]);
        }
        tmp = "";
        for(it = setch.begin(); it!=setch.end(); it++){
            tmp += *it;
        }
        setch.clear();
        setstr.insert(tmp);
    }
    cout << setstr.size() << endl;
    return 0;
}