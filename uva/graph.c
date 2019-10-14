#include <stdlib.h>
#include <stdio.h>

typedef long long lint;

const lint N = 10000000000;
const lint INF = 0x7fffffff;

typedef struct point{
    lint x, y;
} point;

point make_point(lint x, lint y){
    point tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

typedef struct queue{
    lint arr[100];
    lint back, front, M;
}queue;

void init_queue(queue *self){
    self->back = self->front = -1;
    self->M = 100;
}

void push(queue *self, lint value){
    self->back = (1+self->back)%self->M;
    self->arr[self->back] = value;

}

lint front(queue *self){
    return self->arr[1+self->front];
}

void pop(queue *self){
    self->front = (1+self->front)%self->M;
}

int empty(queue *self){
    if(self->front == self->back)
        return 1;
    return 0;
}

typedef struct vector{
    lint *value;
    int size;
} vector;

void init_vector(vector *self){
    self->value = NULL;
    self->size = 0;
}

void push_back(vector *self, lint value){
    if(self->value == NULL){
        self->value = (lint*)malloc(sizeof(lint));
        self->value[0] = value;
        self->size = 1;
        return ;
    }
    self->value = (lint*)realloc(self->value, (1+self->size)*sizeof(lint));
    self->value[self->size] = value;
    self->size++;
}

void clear(vector *self){
    free(self->value);
}

lint cost[11][11], dist[11];
vector graph[11], list;
point p[11];

lint find_order(lint x, lint y){
    lint hash = x*N+y;
    int i;
    for(i = 0; i < list.size; i++){
        if(list.value[i] == hash)
            return i+1;
    }

    push_back(&list, hash);
    p[list.size].x = x;
    p[list.size].y = y;
    return list.size;
}

void bfs(lint x){
    dist[x] = 0;
    queue que;
    init_queue(&que);
    push(&que, x);
    while(!empty(&que)){
        lint u = front(&que);
        pop(&que);
        int i;
        for(i = 0; i < graph[u].size; i++){
            lint v = graph[u].value[i];
            if(dist[v] > dist[u]+cost[u][v]){
                dist[v] = dist[u]+cost[u][v];
                push(&que, v);
            }
        }
    }
}

int main(){

    int t, i, j;
    scanf("%d", &t);
    while(t--){

        for(i = 0; i < 11; i++)
            init_vector(&graph[i]);
        init_vector(&list);

        lint n, x1, x2, y1, y2, d, x, y;

        scanf("%lld%lld%lld", &x, &y, &n);
        find_order(0, 0);
        find_order(x, y);
        for(i = 0; i < 11; i++){
            dist[i] = INF;
            for(j = 0; j < 11; j++)
                cost[i][j] = cost[j][i] = -1;
        }
        int flag[11][11];
        for(i = 0; i < 11; i++)
            for(j = 0; j < 11; j++)
                flag[i][j] = 0;
        
        for(i = 0; i < n; i++){
            scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &d);
            lint a, b;
            a = find_order(x1, y1);
            b = find_order(x2, y2);
            push_back(&graph[a], b);
            push_back(&graph[b], a);
            cost[b][a] = cost[a][b] = d;
            flag[i][j] = 1;
        }
        printf("%d\n", list.size);
        for(i = 1; i <= list.size; i++){
            for(j = i+1; j <= list.size; j++){
                if(cost[i][j] == -1){
                    lint d1 = p[i].x - p[j].x;
                    lint d2 = p[i].y - p[j].y;
                    int k;
                    for(k = 0; k < graph[j].size; k++)
                        if(flag[j][j]){
                            
                        }
                    push_back(&graph[i], j);
                    push_back(&graph[j], i);
                }
            }
        }
        bfs(find_order(0, 0));
        for(i = 1; i < list.size; i++)
            printf("%lld ", dist[i]);
        printf("\n");
        for(int i = 0; i < 11; i++)
            free(&graph[i]);
        free(&list);
    }
    return 0;
}