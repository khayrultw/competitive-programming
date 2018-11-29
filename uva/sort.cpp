#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;

int Pertition(int *arr,int low,int high);
void QuickSort(int *arr,int low,int high);
void heapsort(int *a, int n);
void max_heapify(int *a, int i, int n);
void build_maxheap(int *a, int n);
void insertionSort(int arr[], int length);
void MergeSort(int *arr,int low,int high);
void Merge(int *arr,int low,int mid, int high);
void show(int *a,int n);

int arr[1000000],tmp[1000000], temp[1000000];
int main()
{
        int n,i;
        clock_t time ;
        cin >> n ;
        for(i=1;i<=n;i++)
        {
            arr[i] = rand()%1000000000 ;
            tmp[i] = arr[i] ;
        }
        time = clock() ;
        QuickSort(arr,1,n);
        cout << "Quicksort : " << (1.00*clock()-time)/CLOCKS_PER_SEC << endl;
        //show(arr,n);
        for(i=1;i<=n;i++)
        {
            arr[i] = tmp[i];
        }
        time = clock() ;
        MergeSort(arr,1,n);
        cout << "Mergesort : " << (1.00*clock()-time)/CLOCKS_PER_SEC << endl;
        //show(arr,n);
        for(i=1;i<=n;i++)
        {
            arr[i] = tmp[i];
        }
        time = clock() ;
        heapsort(arr,n);
        cout << "Heapsort : " << (1.00*clock()-time)/CLOCKS_PER_SEC << endl;
        //show(arr,n);
        for(i=1;i<=n;i++)
        {
            arr[i] = tmp[i];
        }
        time = clock() ;
        insertionSort(arr,n);
        cout << "Insertionsort : " << (1.00*clock()-time)/CLOCKS_PER_SEC << endl;
        //show(arr,n);
        return 0;
}

int Pertition(int *arr,int low,int high)
{
        int i,index,pvt,tmp;
        pvt = arr[high];
        index = low;
        for(i=low;i<high;i++)
        {
                if(arr[i]<pvt)
                {
                        tmp=arr[index];
                        arr[index]=arr[i];
                        arr[i]=tmp;
                        index++;
                }
        }

        tmp=arr[high];
        arr[high]=arr[index];
        arr[index]=tmp;
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

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

void insertionSort(int arr[], int length) {
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}

void MergeSort(int *arr,int low,int high)
{
    int mid;
    mid=(low+high)/2;
    if(low<high)
    {
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
    }
    Merge(arr,low,mid,high);
}

void Merge(int *arr,int low,int mid, int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    for(k=low;k<=high;k++)
    {

        if(i==mid+1) temp[k]=arr[j++];
        else if(j==high+1) temp[k]=arr[i++];
        else if(arr[i]<arr[j]) temp[k]=arr[i++];
        else temp[k]=arr[j++];
    }
    for(i=low;i<=high;i++)
    {
           arr[i]=temp[i];
    }
}


void show(int *a,int n)
{
     for(int i=1;i<=n;i++)
                cout << a[i] <<" ";
        cout << endl;
}



