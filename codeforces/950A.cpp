#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int def=abs(a-b);
	if(a<b)
		swap(a,b);
	if(def<=c)
	{
		b+=def;
		c-=def;
		a+=c/2;
		b+=c/2;
	}
	else
		b+=c;
	if(a==0 || b==0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << 2*b << endl;
	return 0;
}
	
