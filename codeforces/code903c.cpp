#include<bits/stdc++.h>

using namespace std;

int check(vector<int> v)
{
	
	if(v.size()==0)
		return 0;
		
	if(v.size()==1)
		return 1;
		
	if(v[v.size()-1] == v[0])
		return v.size();
		
		
	vector<int> v1;
	int k = 0;
	//cout << "NO" << endl;
	for(int i = 1; i < v.size(); i++)
	{
		if(v[k] == v[i])
			v1.push_back(v[i]);
		else
			k++;
	}
	sort(v1.begin(), v1.end());
	return 1+check(v1);
}

int main()
{
	int n, x;
	vector<int> v;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << check(v) << endl;
	return 0;
}
