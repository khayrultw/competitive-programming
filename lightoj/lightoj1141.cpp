#include<bits/stdc++.h>

using namespace std;

bool f;
int df[101][1001] = {-1};

bool isPrime(int n)
{
	if(n==2)
		return true;
	if(n%2==0 || n==1)
		return false;
	for(int i=3;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int dfs(int a, int b)
{
	//cout << a << endl;
	if(df[a][b] != -1)
		return df[a][b] ;
	if(a>b || (b > a && a < 3))
	{
		return 4000000;
	}
	int maxx = 4000000;
	for(int i=a/2;i>=2;i--)
	{
		if( a % i == 0 && isPrime(i))
		{
			df[a][b] = 1+dfs(a+i, b);
			maxx = min(df[a][b], maxx);
			//cout << maxx << endl;
		}
	}
	return maxx;
}

int main()
{
	int t, cas = 0, a, b;
	cin >> t;
	while(++cas<=t)
	{
		cin >> a >> b;
		if(a==b)
		{
			cout << "Case " << cas << ": 0" << endl;
			continue;
		}
		f = true;
		int sum = dfs(a, b);
		if(sum < 2000000)
			cout << "Case " << cas << ": " << sum << endl;
		else
			cout << "Case " << cas << ": -1" << endl;
	}
	return 0;
}

