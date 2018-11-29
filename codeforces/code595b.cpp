#include<bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> intVal, gr;
    vector<string> strv;
    map<string, int> cost;
    string str;
    int n, k, m, x, tmp;
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        strv.push_back(str);

    }
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        intVal.push_back(tmp);
    }
    for(int i = 0; i < k; i++)
    {
        cin >> x;
        int mn = 1000000001;
        for(int j = 0; j < x; j++)
        {
            cin >> tmp;
            gr.push_back(tmp);
            if(intVal[tmp-1] < mn)
                mn  = intVal[tmp-1];
        }
        //cout << mn << endl;
        for(int j = 0; j < x; j++)
        {
            cost[strv[gr[j]-1]] = mn;
            //cout << strv[gr[j]-1] << " " << mn << endl;
        }
        gr.clear();
    }
    long long sum = 0;
    for(int j = 0; j < m; j++)
    {
        cin >> str;
        sum += cost[str];
    }
    cout << sum << endl;
    return 0;
}