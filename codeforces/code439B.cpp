#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b)
{
	if(a == b+1)
		return a%10;
	return ((a%10)*bigMod(a-1,b))%10;
}

int main()
{
	ll a, b;
	cin >> b >> a;
	if(a==b)
		cout << 1 << endl;
	else if(a-b>10)
		cout << 0 << endl;
	else
		cout << bigMod(a,b) << endl;
	return 0;
}
