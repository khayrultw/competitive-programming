#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	int low, high=0, sum=0, a=0;
	cin >> str;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == 'Q')
		{
			for(int j = i+1; j<str.size();j++)
			{
				if(str[j] =='Q')
				{
					for(int k = i+1; k < j ; k++)
					{
						if(str[k] == 'A')
							sum++;
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
