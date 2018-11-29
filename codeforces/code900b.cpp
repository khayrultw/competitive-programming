#include<bits/stdc++.h>

using namespace std;

int f;

bool find(int a, int b, int c)
{
	//cout << "YES" << endl;
	if(a == 0 && c == 0)
	{
		f++;
		return true;
	}
	if(f > 1000 || (a == 0 && c != 0))
		return false;
	if(a >= b)
	{
		f++;
		if(a/b == c)
			return true;
		//cout << "No" << endl;}
		cout << a/b;
		return find(a%b, b, c);
	}
	
	if(a < b )
	{
		while(a < b)
			a = a*10;
	}
	return find(a, b, c);
}

int main()
{
	int a, b, c;
	f = 0;
	cin >> a >> b >> c;
	
	if(find(a%b, b, c))
		cout << f << endl;
	else
		cout << -1 << endl;
	return 0;
}

