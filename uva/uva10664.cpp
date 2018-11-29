#include <bits/stdc++.h>

using namespace std;

bool flag[21][4001];

int main(){

    //freopen("in.txt", "r", stdin);
    int arr[21], n;
    cin >> n;
    cin.ignore();
    while(n--){

        string str;
        int tmp;
        getline(cin, str);
        stringstream in(str);
        int i = 0, sum = 0;

        while(in >> tmp){

            arr[++i] = tmp;
            sum += tmp;
        }
        int k = i;
        //cout << sum << endl;
        if(sum&1){

            cout << "NO" << endl;
            continue;
        }
        sort(arr+1, arr+k+1);
        sum /= 2;
        memset(flag, false, sizeof(flag));
        for(i = 0; i <= k; i++) flag[i][0] = true;
        for(i = 1; i <= sum; i++) flag[0][i] = false;
        for(i = 1; i <= k; i++){

            //cout << arr[i] << endl;
            for(int j = 1; j <= sum; j++){

                if(arr[i]>j) flag[i][j] = flag[i-1][j];
                else flag[i][j] = flag[i-1][j-arr[i]] || flag[i-1][j];
                //cout << flag[i][j] << " ";
            }
            //cout << "*" << endl;
        }
        if(flag[k][sum])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
