#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int i, j, t, n, sum, *ptr, *flag;
    scanf("%d", &t);
    while(t--){
        sum = 0;
        scanf("%d", &n);
        ptr = (int*)malloc(n*sizeof(int));
        for(i = 0; i < n; i++){
            scanf("%d", ptr+i);
            sum += ptr[i];
        }
        qsort(ptr, n, sizeof(int), cmp);
        flag = (int*)malloc((1+sum/2)*sizeof(int));
        flag[0] = 1;
        for(i = 1; i <= sum/2; i++)
            flag[i] = 0;
        for(i = 0; i < n; i++){
            for(j = sum/2; j >= 1; j--){
                if(j < ptr[i])
                    continue;
                flag[j] = flag[j] || flag[j-ptr[i]]; 
            }
        }

        for(i = sum/2; i >= 0 ; i--)
        {
            if(flag[i] == 1){
                printf("%d\n", sum-2*i);
                break;
            }
        }
        free(ptr);
        free(flag);
    }
    return 0;
}