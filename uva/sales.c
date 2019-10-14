#include <stdio.h>

typedef struct Node{
    int x, y;
}Node;

Node casto[10];
int size, ans;
Node home, office;

int index_of(Node node)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(node.x == casto[i].x && node.y == casto[i].y)
            return i;
    }
    return -1;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int dist(Node a, Node b)
{
    int d1, d2;
    d1 = a.x-b.x;
    if(d1 < 0)
        d1 = -1*d1;
    d2 = a.y-b.y;
    if(d2 < 0)
        d2 = -1*d2;
    return d1+d2;
}

void go(int *ptr, int l, int r)
{
    int dst;
    int i,j;
    if(l == r)
    {   
        dst = dist(home, casto[ptr[0]]);

        for(i = 1; i < size; i++)
            dst += dist(casto[ptr[i-1]], casto[ptr[i]]);
        
        dst += dist(casto[ptr[size-1]], home);
        if(dst < ans)
            ans = dst;
        return ;
    }
    for(i = l; i <= r; i++)
    {
        swap(&ptr[l], &ptr[i]);
        go(ptr, l+1, r);
        swap(&ptr[l], &ptr[i]);
    }
}

int main()
{
    int t, i, xx, yy;
    int parm[10];

    scanf("%d", &t);
    while(t--)
    {
        size = 0;
        scanf("%d%d", &xx, &yy);
        scanf("%d%d", &home.x, &home.y);
        scanf("%d", &size);
        for(i = 0; i < size; i++)
            scanf("%d%d", &casto[i].x, &casto[i].y);
        
        for(i = 0; i < size; i++)
            parm[i] = i;

        ans = 0x0fffffff;
        go(parm, 0, size-1);
        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}