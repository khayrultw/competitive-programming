#include<bits/stdc++.h>

using namespace std;

void fun(long long &a, long long &b)
{
	//cout << a << " " << b << endl;
	long long tmp;
	if(a==0 || b==0)
		return ;
	else if(a>=2*b)
	{
		tmp=a/(2*b);
		if(tmp)
			a=a-2*b*tmp;
		else
			a=a-2*b;
		fun(a,b);
	}
	else if(b>=2*a)
	{
		tmp=b/(2*a);
		if(tmp)
			b=b-2*a*tmp;
		else
			b=b-2*a;
		fun(a,b);
	}
	else
		return ;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	fun(a,b);
	cout << a << " " << b << endl;
}
		
		
