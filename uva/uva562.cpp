#include <bits/stdc++.h>

using namespace std;

int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n;
    cin >> t;
    while(t--){

        cin >> n;
        vector <int> v(n+1);
        int sum = 0;
        v[0] = 0;
        for(int i = 1; i <= n; i++){

            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        bool arr[n+1][sum/2+1];
        for(int i = 0; i <= n; i++)
            arr[i][0] = true;
        for(int i = 1; i <= sum/2; i++)
            arr[0][i] = false;
        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= sum/2; j++){

                if(j<v[i]) arr[i][j] = arr[i-1][j];
                else arr[i][j] = arr[i-1][j] || arr[i-1][j-v[i]];
            }
        }
        for(int i = sum/2; i >= 0; i--){

            if(arr[n][i])
            {
                cout << sum - 2*i << endl;
                break;
            }
        }
    }
    return 0;
}
