#include <stdio.h>

int data[] = {1, 2, 3, 4};
int arr[5];

void go(int n, int ind, int i)
{
    int j;
    if(i >= n)
    {
        for(j = 0; j < ind; j++)
            printf("%d ", arr[j]);
        printf("\n");
        return ;
    }
    arr[ind] =  data[i];
    go(n, ind+1, i+1);
    go(n, ind, i+1);
}

int main()
{
    go(4, 0, 0);
}