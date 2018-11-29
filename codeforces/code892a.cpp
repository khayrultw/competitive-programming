#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long a[100001], c[100001], n, max1, max2, sum=0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	cin >> c[0];
	max1 = c[0];
	int ind = 0;
	for(int i = 1;  i < n; i++)
	{
		cin >> c[i];
		if(max1 < c[i]){
			max1 = c[i];
			ind = i;
		}
	}
	if(ind==0)
		max2 = c[1];
	else
		max2 = c[0];
	for(int i = 0; i < n; i++)
	{
		if(i == ind)
			continue;
		if(max2 < c[i])
			max2 = c[i];
	}
	//cout << max1 <<" "<< max2 << endl;

	if(max1 + max2 >= sum)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}


