#include <stdio.h>

int data[] = {1, 2, 3, 4, 5};
int arr[10];

void combin(int n, int r, int ind, int i)
{
    int j;
    if(ind == r)
    {
        for(j = 0; j < r; j++)
            printf("%d ", arr[j]);
        printf("\n");
        return ;
    }

    if(i >= n)
        return ;
    
    arr[ind] = data[i];
    combin(n, r, ind+1, i+1);
    combin(n, r, ind, i+1);
}
int main()
{
    combin(5, 2, 0, 0);
}