#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		int indx, one = 0;
		
		cin >> n;
		
		int dig = log2(n);
		
		bool f = true;
		
		//cout << dig << endl;
		
		for(int i = 0; i <= dig; i++)
		{
			if( n & (1<<i))
			{
				if(f)
				{
					f = false;
					
					indx = i;
				}
				one++;
			}
		}
		
		//cout << "ONE " << one << endl;
		
		int indx0 = -1;
		
		for(int i = indx+1; i <= dig; i++)
		{
			//cout << (n & (1<<i)) << endl;
			
			if( (n & (1<<i)) == 0)
			{
				indx0 = i;
				
				break;
			}
		}
		if( indx0 == -1)
		{
			for(int i = indx; i < dig; i++)

				n = n ^ (1 << i);
				
			n = n << 1;
			
			//cout << "-1 " <<  n << endl;
			
			for(int i = 0; i < one-1; i++)
			
				n = n | (1 << i);
		}
		
		else
		{
			n = n ^ (1 << indx0);
			
			n = n ^ (1 << (indx0 - 1));
			
			one = 0;
			for( int i = 0; i < indx0; i++)
			{
				if( (n & (1<<i)))
				{
					one++;
					n = n ^ (1<<i);
				}
			}
			for(int i = 0; i < one; i++)
				n = (n | (1<<i));
		}
		
		cout << "Case " << cas << ": " << n << endl;
		
	}
	return 0;	
}
