#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,x;
	cin >> n >> m;
	if(n>31)
	{
		x = m;
		goto lb;
	}
	x = (1<<n);
	x--;
	x = m&x;
lb: cout << x << endl;
	return 0;
}


