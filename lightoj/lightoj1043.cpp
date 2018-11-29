#include<bits/stdc++.h>

using namespace std;

#define ERR 0.00000001

int main()
{
	double ab, ac, bc, k, x, ad, ae, de;
	int t, cas = 0;
	cin >> t;
	while( ++cas <= t)
	{
		cin >> ab >> ac >> bc >> k;
		double low = 0, high = ab;
		while(abs(low - high) > ERR)
		{
			ad = (low + high) / 2;
			double S, s, z = ad / ab;
			ae = z * ac;
			de = z * bc;
			S = ab + bc + ac;
			s = ad + ae + de;
			double del1, del2 = s * (s - ad) * (s - ae) * ( s - de);
			del1 = (S * (S - ab) * (S - ac) * (S - bc));
			cout << del1 << " " << del2 << endl;
			double del = del2 / (del1 - del2);
			cout << del << endl;
			if(del > k * k)
				high = ad;
			else
				low = ad;
		}
		cout << ad << endl;
	}
	return 0;
}
