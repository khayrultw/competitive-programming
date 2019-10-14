#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int d, v, i;
} node;

typedef struct vector{
    node *value;
    int size;
} vector;

node make_node(int _d, int _v, int _i){
    node tmp;
    tmp.d = _d;
    tmp.v = _v;
    tmp.i = _i;
    return tmp;
}

void init_vector(vector *self){
    self->value = NULL;
    self->size = 0;
}

void push_back(vector *self, node value){
    if(self->value == NULL){
        self->value = (node*)malloc(sizeof(node));
        self->value[0] = value;
        self->size = 1;
        return ;
    }
    self->value = realloc(self->value, (1+self->size)*sizeof(node));
    self->value[self->size] = value;
    self->size++;
}

int cmp1(const void *a, const void *b){
    return ((node*)a)->d - ((node*)b)->d;
}

int cmp2(const void *a, const void *b){
    return ((node*)a)->i - ((node*)b)->i;
}

int main(){
    int t, w, n, i, j;
    node *ptr;
    int **dp, f;
    f = 0;
    while(scanf("%d %d", &t, &w) == 2){
        scanf("%d", &n);
        ptr = (node*)malloc(n*sizeof(node));
        for(i = 0; i < n; i++){
            ptr[i].i = i;
            scanf("%d %d", &ptr[i].d, &ptr[i].v);
        }
        qsort(ptr, n, sizeof(node), cmp1);
        dp = (int**)malloc((n+1)*sizeof(int*));
        for(i = 0; i <= n; i++)
            dp[i] =  (int*)malloc((t+1)*sizeof(int));
        for(i = 0; i <= n; i++)
            for(j = 0; j <= t; j++)
                dp[i][j] = 0;
        
        for(i = 0; i < n; i++){
            for(j = 1; j <= t; j++){
                if(j < 3*w*ptr[i].d)
                    dp[i+1][j] = dp[i][j];
                else
                {
                    if(ptr[i].v+dp[i][j-3*w*ptr[i].d] > dp[i][j])
                        dp[i+1][j] = ptr[i].v+dp[i][j-3*w*ptr[i].d];
                    else
                        dp[i+1][j] = dp[i][j];
                    
                }  
            }
        }
        if(f)
            printf("\n");
        f = 1;
        printf("%d\n", dp[n][t]);
        vector ans;
        init_vector(&ans);
        i = n;
        j = t;
        while(i>0 && j>0){
            if(dp[i][j] == dp[i-1][j])
                i--;
            else{
                push_back(&ans, ptr[i-1]);
                i--;
                j -= 3*w*ptr[i-1].d;
            }
        }
        qsort(ans.value, ans.size, sizeof(node), cmp2);
        printf("%d\n", ans.size);
        for(i = 0; i < ans.size; i++){
           printf("%d %d\n", ans.value[i].d, ans.value[i].v);
        }
        for(i = 0; i <= n; i++)
            free(dp[i]);
        free(dp);
        free(ptr);
        free(ans.value);
    }
    return 0;
}