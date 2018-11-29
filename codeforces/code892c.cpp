#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	return gcd(b, a%b);
}

bool flag;

int fun(int a[], int n)
{
	if(n==1 && a[0]!=1)
	{
		flag = true;
		return 0;
	}
	if(n==1)
		return 0;
	int tmp[n-1], k = -1;
	for(int i = 0; i < n-1; i++)
	{
		tmp[++k] = gcd(a[i], a[i+1]);
		if(tmp[k] == 1)
			return 1;
	}
	return 1 + fun(tmp, n-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a[2000];
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	flag = false;
	int sum = fun(a, n) + n - 1;
	if(flag)
		cout << -1 << endl;
	else
		cout << sum << endl;
	return 0;
}

