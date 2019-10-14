#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main(){
    int a;
    cin >> a;
    while(sumOfDigits(a) % 4){
        a++;
    }
    cout << a << endl;
    return 0;
}