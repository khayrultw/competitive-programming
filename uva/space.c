#include <stdio.h>

#define INF 0x1fffffff

typedef struct Node
{
    int x, y;
}Node;

Node point[100];
int size, n;
int adj[100][100];

int abs(int x)
{
    return (x > 0)?x: -1*x;
}

int dist(Node a, Node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int index_of(Node node)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(point[i].x == node.x && point[i].y == node.y)
            return i;
    }
    point[size] = node;
    size++;
    return size-1;
}

int main()
{
    int i,j, cost, k;
    int d1,d2;
    Node a, b;
    scanf("%d%d", &d1, &d2);
    scanf("%d", &n);
    a.x = a.y = 0;
    index_of(a);
    for(i = 0; i < 2*n+2; i++)
        for(j = 0; j < 2*n+2; j++)
            adj[i][j] = INF;

    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &cost);
        adj[index_of(a)][index_of(b)] = cost;
        adj[index_of(b)][index_of(a)] = cost;
    }

    b.x = d1-1;
    b.y = d2-1;
    index_of(b);
    printf("%d\n", size);
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(adj[i][j] == INF)
            {
                cost = dist(point[i], point[j]);
                adj[i][j] = cost;
                adj[j][i] = cost;
            }
        }
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    for(k = 0; k < size; k++)
        for(i = 0; i < size; i++)
            for(j = 0; j < size; j++)
                if(adj[i][j] > adj[i][k]+adj[k][j])
                    adj[i][j] = adj[i][k]+adj[k][j];
    
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    a.x = a.y = 0;
    b.x = d1-1;
    b.y = d2-1;
    printf("%d\n", adj[index_of(a)][index_of(b)]);
    return 0;
}