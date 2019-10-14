#include <iostream>

using namespace std;

string war[26];
int n;

bool isValid(int i, int j){
    if(i >= n || i < 0)
        return false;
    if(j >= n || j < 0)
        return false;
    if(war[i][j] == '0')
        return false;
    return true;
}

void dfs(int i, int j){
    if(!isValid(i, j)){
        return ;
    }
    war[i][j] = '0';
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i-1, j-1);
    dfs(i-1, j+1);
    dfs(i+1, j-1);
    dfs(i+1, j+1);
}

int main(){
    //freopen("out.txt", "w", stdout);
    int t = 0;
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> war[i];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(war[i][j] == '1'){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << "Image number " << ++t << " contains " << ans << " war eagles." << endl;
    }
    return 0;
}