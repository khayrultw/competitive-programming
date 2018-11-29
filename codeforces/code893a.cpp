#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int player1, player2, spact;

bool find(int player1, int player2, int spact, int at)
{
	//cout << at << endl;
	if(at >= v.size())
		return true;
	if(v[at] == player1)
		return find(player1, spact, player2, at+1);
	if(v[at] == player2)
		return find(player2, spact, player1, at+1);
	return false;
}

int main()
{
	int n, tmp;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	if(find(1, 2, 3, 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
	
