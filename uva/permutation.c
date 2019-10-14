#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *value;
    int size;
} vector;

void push(vector *self, int value){
    if(self->value == NULL){
        self->value = (int*)malloc(sizeof(int));
        self->value[self->size] = value;
        self->size = 1;
        return ;
    }
    self->value = realloc(self->value, (1+self->size)*sizeof(int));
    self->value[self->size] = value;
    self->size++;
}

void init(vector *self){
    self->size = 0;
    self->value = NULL;
}

void delete(vector *self){
    free(self->value);
    free(self);
}

int main(){
    vector *vec;
    vec = (vector*)malloc(sizeof(vector));
    init(vec);
    for(int i = 0; i < 10; i++)
        push(vec, i);
    for(int i = 0; i < 10; i++)
        printf("%d\n", vec->value[i]);
    delete(vec);
    return 0;
}