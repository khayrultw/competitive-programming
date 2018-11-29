#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n1, n2, n3, x[100001];
	stack<int> stack1, stack2, stack3;
	stack1.push(0) ; stack2.push(0); stack3.push(0);
	cin >> n1 >> n2 >> n3;
	for(int i=0;i<n1;i++)
	{
		cin >> x[i];
	}
	for(int i=n1-1;i>=0;i--)
	{
		stack1.push(stack1.top()+x[i]);
	}
	for(int i=0;i<n2;i++)
	{
		cin >> x[i];
	}
	for(int i=n2-1;i>=0;i--)
	{
		stack2.push(stack2.top()+x[i]);
	}
	for(int i=0;i<n3;i++)
	{
		cin >> x[i];
	}
	for(int i=n3-1;i>=0;i--)
	{
		stack3.push(stack3.top()+x[i]);
	}
	while(1)
	{
		if(stack1.top()==stack2.top() && stack2.top()==stack3.top())
			break;
		else
		{
			if(stack1.top()>stack2.top())
				stack1.pop();
			else if(stack3.top()>stack2.top())
				stack3.pop();
			else
				stack2.pop();
		}
	}
	cout << stack1.top() << endl;
	return 0;
}
