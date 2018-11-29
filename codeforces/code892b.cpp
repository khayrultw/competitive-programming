#include<bits/stdc++.h>

using namespace std;

int main()
{
	int guil[1000001], arr[1000001], dead, n, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &guil[i]);
		arr[i] = i - guil[i];
	}
	dead = n + 1;
	for( int i = n; i >= 1; i--)
	{
		if(i < dead)
			sum++;
		dead = min(dead, arr[i]);
	}
	cout << sum << endl;
	return 0;
}
		
