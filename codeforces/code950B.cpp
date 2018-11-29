#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,sum1,sum2,a[100001],b[100001],file;
	sum1=sum2=file=0;
	cin >> n >> m;
	for(int i=0; i<n;i++)
		scanf("%I64d",&a[i]);
	for(int i=0; i<m;i++)
		scanf("%I64d",&b[i]);
	int i,j;
	i=j=0;
	while(true)
	{
		if(i==n || j==m)
			break;
		if(sum1==0 && sum2==0)
		{
			sum1+=a[i++];
			sum2+=b[j++];
		}
		else if(sum1<sum2)
			sum1+=a[i++];
		else if(sum2<sum1)
			sum2+=b[j++];
		else;
		
		if(sum1==sum2)
		{
			file++;
			sum1=sum2=0;
		}
	}
	if(i!=n || j!=m)
		file++;
	cout << file << endl;
	return 0;
}
