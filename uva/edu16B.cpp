#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,arr[300001];
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	sort(arr+1,arr+n+1);
	cout << arr[(n+1)/2] << endl;
	return 0;
}
