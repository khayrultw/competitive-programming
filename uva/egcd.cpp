#include<bits/stdc++.h>

using namespace std;

#define _ <<" "<<
void  egcd(int a, int b, int &x, int &y)
{
	if(a==0)
	{
		x = 0;
		y = 1;
		return ;
	}
	int x1, y1;
	egcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	cout << a _ b << endl;
	cout << x _ y << endl;
	return ;
}
int main()
{
	int x, y;
	egcd(5, 4, x, y);
	cout << x _ y << endl;
	return 0;
}
