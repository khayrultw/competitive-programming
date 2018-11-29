#include<iostream>

using namespace std;

int Pertition(int *arr,int low,int high);
void QuickSort(int *arr,int low,int high);

int main()
{
	int n,i,arr[100];
	cin >> n ;
	for(i=0;i<n;i++)
		cin >> arr[i]  ;
	QuickSort(arr,0,n-1);
	for(i=0;i<n;i++)
		cout << arr[i] <<" ";
	cout << endl;
	return 0;
}

int Pertition(int *arr,int low,int high)
{
	int i,index,pvt,tmp;
	pvt = arr[high];
	index = low ;
	for(i=index+1;i<high;i++)
	{
		if(pvt>arr[i])
		{
			tmp=arr[index];
			arr[index]=arr[i];
			arr[i]=tmp;
		}
		index++;
	}
	tmp=arr[high];
	arr[high]=arr[index];
	arr[index]=tmp;
	for(i=low;i<=index;i++)
		cout << arr[i] << " " ;
	cout << endl;
	for(i=low;i<=index;i++)
                cout << arr[i] << " " ;
	cout << endl;
	return index;
}

void QuickSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pvt = Pertition(arr,low,high);
		QuickSort(arr,low,pvt-1);
		QuickSort(arr,pvt+1,high);
	}
}
