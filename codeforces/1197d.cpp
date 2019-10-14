#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

lint n, m, k;
lint maxSubArraySum(vector<lint> a) 
{ 
    lint max_so_far = INT_MIN, max_ending_here = 0; 
    lint prev = 0, ans = 0;
    for (int i = 0; i < a.size(); i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here){ 
            max_so_far = max_ending_here;
            lint temp = max_so_far - k*ceil(1.00*(i-prev+1)/m);
            if(ans < temp)
            {
                ans = temp;
            }
        }

  
        if (max_ending_here < 0)
        {
            max_ending_here = 0; 
            prev = i+1;
        }
    } 
    return ans; 
} 

int main() {
    cin >> n >> m >> k;
    vector<lint> v(n);
    for(lint i = 0; i <= n; i++)
    {
        cin >> v[i];
    }

    cout << maxSubArraySum(v) << endl;
    return 0;
}