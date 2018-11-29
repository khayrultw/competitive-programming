#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, sum, tmp;
	set<int> st;
	set<int> :: iterator it;
	cin >> n;
	bool f = false;
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		st.insert(tmp);
		if(tmp==0)
			f = true;
	}
	sum = st.size();
	if(f)
		sum--;
	cout << sum << endl;
	return 0;
}

	
