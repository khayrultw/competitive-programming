#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x[6];
	for(int i = 0; i < 6; i++)
		cin >> x[i];
	sort(x, x+6);
	if(x[0] + x[4] + x[5] == x[1] + x[2] + x[3] || x[0] + x[1] + x[5] == x[2] + x[3] + x[4])
		cout << "YES" << endl;
	else if(x[0] + x[4] + x[3] == x[1] + x[2] + x[5] || x[2] + x[1] + x[5] == x[0] + x[3] + x[4])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
