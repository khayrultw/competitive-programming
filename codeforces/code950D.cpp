#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b, c, sum, tmp;
	cin >> a >> b;
	for(int i=0; i<b;i++)
	{
		scanf("%I64d",&c);
		if(c&1){
			printf("%I64d\n",(1+c/2));
			continue;
		}
		tmp = c/2;
		tmp =a-tmp+c;
		while(1){
			if(tmp&1)
				break;
			else
				tmp+=(a-tmp/2);
			//cout << tmp << endl;
				
		}
		printf("%I64d\n",tmp/2+1);
	}
	return 0;
}
			
