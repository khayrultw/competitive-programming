#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		stack<int> st;
		cin >> s;
		for(int j=0; j<s.size(); j++)
		{
			if(s[j] == ')' || s[j] == '}' || s[j] ==']')
			{
				if(st.empty())
				{
					st.push((int)s[j]);
					break;
				}
				else 
				{
					//cout << st.top() << " YES " << (int)s[j] << endl;
					if(st.top()==(int)s[j]-1 || st.top()==(int)s[j]-2)
					{
						//cout << st.top() << " YES " << s[j] << endl;
						st.pop();
					}
					else
						break;
				}
			}
			else
				st.push((int)s[j]);
		}
		if(st.empty())
			cout << "YES" << endl; 
		else
			cout << "NO" << endl;
	}
	return 0;
}
			
