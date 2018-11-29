#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,tmp,sum=0;
	cin >> n;
	while(n--)
	{
		cin >> tmp;
		sum+=abs(tmp);
	}
	cout << sum << endl;
	return 0;
}
