#include <bits/stdc++.h>

using namespace std;

int mat[101][101];

int main(){
    
    int cas;
    cin >> cas;
    while(cas--){
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        int a, b, c;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    mat[i][j] = 0;
                    continue;
                }
                mat[i][j] = 0x2fffffff;
            }
        }

        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            mat[a][b] = c;
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(mat[i][e] <= t)
                ans++;
        }

        cout << ans << endl;
        if(cas)
            cout << endl;
    }
    return 0;
}