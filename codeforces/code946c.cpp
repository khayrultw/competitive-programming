#include <bits/stdc++.h>
#define ULL unsigned long long int
using namespace std;

int main() {
    ULL a, b, x, y;
    ULL r;
    cin >> a >> b;

    label1:
        if (a == 0 || b == 0) {
            cout << a << " " << b << endl;
            return (0);
        }
    x = 2 * b;
    y = 2 * a;
    if (a >= x) {
        r = a / x;
        a -= (x * r);
        //cout << "a = " << a << endl;
        goto label1;
    }
    if (b >= y) {
        r = b / y;
        b -= (r * y);
        //cout << "b = " << b << endl;
        goto label1;
    }
    cout << a << " " << b << endl;

    return (0);
}
