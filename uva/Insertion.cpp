#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void Insertion(int *a,int n);

int main()
{
	int data[10000] , i , n ;
	clock_t start,end;
	cin >> n ;
	for(i=0;i<n;i++)
		 data[i] = rand()%10000;
	start = clock();
	Insertion(data,n);
	end = clock();
	for(i=0;i<n;i++)
	{
		cout << data[i] << " " ; 
	}
	cout << endl;
	cout << (1.00*end-start)/CLOCKS_PER_SEC << endl;
	return 0;
}

void Insertion(int *a, int n)
{
	int i,tmp,j;
	for(i=0;i<n;i++)
	{
		tmp = a[i] ;
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>tmp)
			{
				a[j+1] = a[j] ;
			}
		}
		a[j+1] = tmp ;
	}
}
