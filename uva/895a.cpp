#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, ang[361], sum, mina, div;
	cin >> n;
	div = sum =0 ;
	for(int i=1; i<=n; i++)
	{
		cin >> ang[i];
		sum += ang[i];
	}
	mina = 10000000;
	for(int i=1; i<=n; i++)
	{
		div += ang[i];
		if(abs(sum - div - div) < mina)
			mina = abs(sum - div - div);
	}
	cout << mina << endl;
	return 0;
}

