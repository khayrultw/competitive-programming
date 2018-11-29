#include<bits/stdc++.h>

using namespace std;

int kur[52], shi[52],kat[52];

int main()
{
    int n, len;
    string a, b, c, str[2];
    str[0] = "Kuro";
    str[1] = "Shiro";
    cin >> n;
    cin >> a >> b >> c;
    len = a.size();
    if(n>=len-1){

        cout << "Draw" << endl;
        return 0;
    }
    for(int i = 0; i < len; i++){
        int x;
        x = a[i]-'a';
        if(a[i]<97)
            x = a[i]-'A'+26;
        kur[x]++;
        x = b[i]-'a';
        if(b[i]<97)
            x = b[i]-'A'+26;
        shi[x]++;
        x = c[i]-'a';
        if(c[i]<97)
            x = c[i]-'A'+26;
        kat[x]++;
    }
    sort(kur,kur+52);
    sort(shi, shi+52);
    sort(kat, kat+52);

    for(int i = 51; i >= 0; i--){
        int x, y;
        if(kur[i] == shi[i] && shi[i] == kat[i])
            continue;
        if(kur[i]>shi[i]){
            x = 0;
            y = kur[i];
        }
        else if(kur[i]<shi[i]){
            x = 1;
            y = shi[i];
        }
        else if(kur[i]<kat[i] && kat[i]>0){
            cout << "Katie" << endl;
            //cout << kur[i] << " " << shi[i] << " " << kat[i] << endl;
            return 0;
        }
        else continue;

        if(y<kat[i] && y>0){
            //cout << kur[i] << " " << shi[i] << " " << kat[i] << endl;
            cout << "Katie" << endl;
            return 0;
        }

        else if(y>kat[i] && y > 0){

           // cout << kur[i] << " " << shi[i] << " " << kat[i] << endl;
            cout << str[x] << endl;
            return 0;
        }
        else continue;
    }
    cout << "Draw" << endl;
    return 0;
}