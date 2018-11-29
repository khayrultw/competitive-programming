#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,n,indx=0;
	cin >> n;
	vector<int> max_val(n+1,0);
	for(int i=0;i<n;i++)
	{
		cin >> a;
		if(a==1)
		{
			cin >> b;
			if(b>max_val[indx])
				max_val[indx+1] = b;
			else
				max_val[indx+1] = max_val[indx];
            indx++;
		}
		else if(a==2 && indx>0)
		{
			indx--;
		}
		else
		{
			cout << max_val[indx] << endl;
		}
	}
	return 0;
}
		
