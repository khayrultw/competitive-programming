#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, pos, neg;
	pos = neg = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d",&a, &b);
		if(a<0)
			neg++;
		if(a>0)
			pos++;
	}
	
	if(pos <= 1 || neg <= 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
		
