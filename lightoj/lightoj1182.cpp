#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t ;
	
	while(++cas <= t)
	{
		int n, one = 0;
		
		cin >> n ;
		
		int dig = log2(n);
		
		for(int i=0; i <= dig; i++)
		{
			if( n & (1 << i))
				one++;
		}
		if(one&1)
			cout << "Case " << cas << ": odd" << endl;
		else
			cout << "Case " << cas << ": even" << endl;
	}
	return 0;
}

