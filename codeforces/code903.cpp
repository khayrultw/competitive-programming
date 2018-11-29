#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x, y, t, i;
	
	cin >> t;
	
	while(t--)
	{
		cin >> x; 
	
		for(i = 0; i <= 20; i++)
		{
			y = (x - 7*i) / 3;
			if(y >= 0 && ceil(1.00 * (x - 7*i)/3) == floor(1.00 * (x - 7*i)/3))
			{
				cout << "YES" << endl;
				break;
			}
		}
		if( i == 21)
			cout << "NO" << endl;
	}
	return 0;
}
