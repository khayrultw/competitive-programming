#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, cas = 0, a, b;
    cin >> t;
    while(++cas <= t){

        string str;
        cin >> str >> a >> b;
        int len = str.size();
        int sum = 0;
        for(int i = a; i <= b; i++){

            if(i<=len)
                sum += len-i+1;
        }
        cout << "Case " << cas << ": " << sum << endl;
    }
    return 0;
}
