
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int i ;
	clock_t start = clock();
	for(i=0;i<100000000;i++);
	clock_t end = clock();
	cout << (1.00*end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
	
