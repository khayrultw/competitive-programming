#include<bits/stdc++.h>

using namespace std;

bool testDiv(string s, long long n)
{
	long long tmp=0;
	int i = 0;
	if(s[i]=='-')
		i++;
	for(; i < s.size(); i++)
	{
		tmp = 10 * tmp + s[i]-'0';
		tmp = tmp % n;
	}
	if(tmp==0)
		return true;
	return false;
}
	
int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		long long b;
		string a;
		cin >> a >> b;
		if(b < 0)
			b = b * -1;
		if(testDiv(a, b))
			printf("Case %d: divisible\n", cas);
		else
			printf("Case %d: not divisible\n", cas);
	}
	return 0;
}
