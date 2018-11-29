#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, l, r;
	
	string s;
	
	char a, b;
	
	cin >> n >> m;
	
	cin >> s;
	for(int i = 0; i < m; i++)
	{
		cin >> l >> r >> a >> b;
		for(int j = l-1; j < r; j++)
		{
			if(s[j] == a){
				s[j] = b;
			}
		}
	}
	cout << s << endl;
	return 0;
}
	
