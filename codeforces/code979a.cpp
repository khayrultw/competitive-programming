#include<iostream>

using namespace std;

int main(){

    long long n;
    cin >> n;
    if(n==0){

        cout << 0 << endl;
        return 0;
    }
    if((n+1)%2==0)
        cout << (n+1)/2 << endl;
    else
        cout << n+1 << endl;
    return 0;
}