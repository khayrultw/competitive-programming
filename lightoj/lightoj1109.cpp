#include<bits/stdc++.h>

using namespace std;

int divi[1001];

bool cmp(const int &a, const int &b)
{
	if(divi[a]==divi[b])
		return a > b;
	return divi[a] < divi[b];
}

int main()
{
	int x[1001];
	
	for(int i = 1; i <= 1000; i++)
	{
		for(int j = i; j <= 1000; j += i)
		{
			divi[j]++;
		}
	}
	for(int i = 1; i <= 1000; i++) x[i] = i;
	
	sort(x, x+1001, cmp);
	
	int t, cas = 0;
	
	cin >> t ;
	
	while(++cas <= t)
	{
		int n;
		cin >> n;
		cout << "Case " << cas << ": " << x[n] << endl;
	}
	return 0;
}
	
	
