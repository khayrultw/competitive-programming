#include<bits/stdc++.h>

using namespace std;

vector<int> v[300001];

int main()
{
    int n, a, b, x, y;
    cin >> n >> a >> b;
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int sum = v[b].size()
}