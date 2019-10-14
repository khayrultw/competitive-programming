#include <iostream>

using namespace std;

void permu(string s, int l, int r){
    if(l == r){
        cout << s << endl;
        return ;
    }
    for(int i = l; i <= r; i++){
        swap(s[l], s[i]);
        permu(s, l+1, r);
        swap(s[l], s[i]);
    }
}
int main(){
    string str = "1234";
    permu(str, 0, str.length()-1);
}