#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>

using namespace __gnu_pbds;  
using namespace std;  
  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
 

int main(){
    int t, cas = 0, n;
    cin >> t;
    while(++ cas <= t){
        ordered_set s;
        cin >> n;
        vector<int> v(n);
        for(int i = 1; i <= n; i++)
            s.insert(i);
        
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        for(int i = v.size()-1; i > 0; i--){
            int k = n - v[i];
            n--;
            s.erase(s.find_by_order(k-1));
        }

        cout << "Case " << cas << ": ";
        cout << *s.find_by_order(0) << endl;
    }
    return 0;
}