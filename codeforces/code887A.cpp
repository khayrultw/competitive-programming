#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int k, i;
	k = i =0;
	cin >> s;
	while(s[i] != '1')
		i++;
	for(; i < s.size(); i++)
		if(s[i] == '0')
			k++;
	if(k>=6)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
