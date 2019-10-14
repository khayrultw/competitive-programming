#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    int x, y;
} pair;

typedef struct queue{
    int front, back, MOD;
    struct pair arr[100000];
} queue;

void init_queue(queue *self){
    self->front = self->back = -1;
    self->MOD = 100000;
}

void enqueue(queue *self, pair value){
    self->back = (self->back+1)%self->MOD;
    self->arr[self->back] = value;
}

struct pair front(queue *self){
    int tmp = (self->front+1)%self->MOD;
    return self->arr[tmp];
}

int empty(queue *self){
    if(self->back == self->front)
        return 1;
    return 0;
}

void pop(queue *self){
    self->front = (self->front+1)%self->MOD;
}

pair make_pair(int _x, int _y){
    pair tmp;
    tmp.x = _x;
    tmp.y = _y;
    return tmp;
}

typedef struct{
    pair *value;
    int size;
} vector;

void push(vector *self, pair value){
    if(self->value == NULL){
        self->value = (pair*)malloc(sizeof(pair));
        self->value[self->size] = value;
        self->size = 1;
        return ;
    }
    self->value = realloc(self->value, (1+self->size)*sizeof(pair));
    self->value[self->size] = value;
    self->size++;
}

void init(vector *self){
    self->size = 0;
    self->value = NULL;
}

void clear_vector(vector *self){
    free(self->value);
    free(self);
}

vector graph[10000];
int dist[100][100], n, m;


void bfs(){
    dist[1][1] = 0;
    queue que;
    enqueue(&que, make_pair(1,1));
    while(!empty(&que)){
        pair tmp = front(&que);
        pop(&que);
        int x = tmp.x*n+tmp.y;
        for(int i = 0; i < graph[x].size; i++){
            if(dist[tmp.x][tmp.y] < dist[graph[x].value[i].x][graph[x].value[i].y]){
                enqueue(&que, graph[x].value[i]);
            }
        }
        
    }
}

int main(){
    for(int i = 100; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dist[i][j] = 0x7fffffff;
        }
    }
    scanf("%d%d", &n, &m);
    int a, b, c, d;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x = a*n+b;
        push(&graph[x], make_pair(c,d));
        x = c*n+d;
        push(&graph[x], make_pair(a, b));
    }
    bfs();
    printf("%d\n", dist[n][n]);
    return 0;
}