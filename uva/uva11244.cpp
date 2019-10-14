#include <bits/stdc++.h>

using namespace std;

vector<string> v;
int n, m;
bool flag[1000][1000];

bool isValid(int i, int j){
    if(i < 0 || j < 0)
        return false;
    if(i >= n || j >= m)
        return false;
    if(v[i][j] == 'L' || flag[i][j])
        return false;
    return true;
}
int dfs(int i, int j){
    if(!isValid(i, j))
        return 0;
    
    flag[i][j] = true;
    int sum = 0;
    sum += dfs(i-1, j);
    sum += dfs(i+1, j);
    sum += dfs(i, j-1);
    sum += dfs(i-1, j-1);
    sum += dfs(i+1, j-1);
    sum += dfs(i, j+1);
    sum += dfs(i-1, j+1);
    sum += dfs(i+1, j+1);   
    return 1+sum;
}
int main(){
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        string str;
        while(getline(cin, str)){
            //cout << " k " <<  str << endl;
            if(str == ""){
                v.clear();
                break;
            }
            if(str[0] == 'L' || str[0] == 'W')
                v.push_back(str);
            
            else{
                stringstream in(str);
                int a, b;
                in >> a >> b;
                n = v.size();
                m = v[0].size();
                memset(flag, false, sizeof(flag));
                cout << dfs(a-1, b-1) << endl;
            }
        }
        if(t) cout << endl;
    }
    return 0;
}