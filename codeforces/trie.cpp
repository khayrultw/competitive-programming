#include<bits/stdc++.h>

using namespace std;

int x[100][255]={-1}, next = 1; //initially all numbers in x are 0
void build(string s){
	int i = 0, v = 1;
	while(i < s.size()){
		if(x[v][s[i]] == 0)
			v = x[v][s[i++]] = next ++;
		else
			v = x[v][s[i++]];
	}
}

int main()
{
	build("123456789");
	for(int i=48; i < 59; i++){
		for(int j=0; j<=9; j++)
			cout << x[j][i] << " ";
	
		cout << endl;
	}
}
