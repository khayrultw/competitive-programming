#include<bits/stdc++.h>

using namespace std;

struct nod
{
	int freq, depth;
	nod *next[4];
	nod()
	{
		freq = depth = 0;
		for(int i=0;i<4;i++)
			next[i] = 0;
	}
};
int max_val;

void freenod(nod *root)
{
	if(max_val < root->freq * root->depth)
		max_val = root->freq * root->depth ;
	for(int i=0; i<4; i++)
	{
		if(root->next[i])
			freenod(root->next[i]);
	}
	delete root;
}

int main()
{
	nod *root,*tmp;
	map<char,int> m;
	m['A'] = 0; m['C'] = 1; m['G'] = 2; m['T'] = 3; 
	int t,n,cas=0;
	string s;
	cin >> t;
	while(++cas<=t)
	{
		root = new nod;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> s;
			tmp = root;
			for(int j=0;j<s.size();j++)
			{
				if(tmp->next[m[s[j]]])
					tmp->next[m[s[j]]]->freq++;
				else
				{
					tmp->next[m[s[j]]] = new nod;
					tmp->next[m[s[j]]]->freq++;
					tmp->next[m[s[j]]]->depth = j+1;
				}
				tmp = tmp->next[m[s[j]]];
			}
		}
		max_val = 0;
		freenod(root);
		cout << "Case " << cas << ": " << max_val << endl;
	}
	return 0;
}
		
		
