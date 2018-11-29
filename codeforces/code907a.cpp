#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d, i;
	cin >> a >> b >> c >> d;
	
	if(2*c >= d)
	{
		for(i = c ; i<=2*c; i++)
		{
			if(i>=d){
				if(i>=b)
					b += i-b+1;
				if(b>=a)
					a += b-a+1;
				cout << a << endl << b << endl << i << endl;
				return 0;
			}
		}
		if(i == 2*c+1)
			cout << -1 << endl;
	}
	
	else 
		cout << -1 << endl;
	return 0;
}
