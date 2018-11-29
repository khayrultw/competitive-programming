#include<bits/stdc++.h>

using namespace std;

int freq(string s,string req)
{
    int sum=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==req[0]&&s[i+1]==req[1])
            sum++;
    }
    return sum;
}

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a,b;
    a = freq(s,"SF");
    b = freq(s,"FS");
    if(a>b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
