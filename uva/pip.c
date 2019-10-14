#include <stdio.h>

#define INF 0x4fffffff
#define MAX 100000

int grid[1001][1001];
int dist[1001][1001];
int vis[1001][1001];
int n, m, endo_len;


typedef struct Node
{
    int _x, _y;
}Node;

typedef struct Queue
{
    Node _arr[MAX];
    int _front, _back;
}Queue;

void init_queue(Queue *que)
{
    que->_front = que->_back = 0;
}

void push(Queue *que, Node value)
{
    //printf("push\n");
    que->_arr[que->_back] = value;
    que->_back = (que->_back + 1)%MAX;
}

Node front(Queue *que)
{
    return que->_arr[que->_front];
}

void pop(Queue *que)
{
    que->_front = (que->_front + 1)%MAX;
}

int empty(Queue *que)
{
    if(que->_front == que->_back)
        return 1;
    
    return 0;
}

int is_valid(int i, int j)
{
    if(i < 0 || i >= n)
        return 0;

    if(j < 0 || j >= m)
        return 0;

    if(grid[i][j] == 0)
        return 0;

    return 1;
}

int is_valid_left(int i, int j)
{
    if(is_valid(i, j) == 0)
        return 0;

    if(grid[i][j] == 1 || grid[i][j] == 3)
        return 1;
    
    if(grid[i][j] == 6 || grid[i][j] == 7)
        return 1;

    return 0;
}

int is_valid_right(int i, int j)
{
    if(is_valid(i, j) == 0)
        return 0;

    if(grid[i][j] == 1 || grid[i][j] == 3)
        return 1;

    if(grid[i][j] == 4 || grid[i][j] == 5)
        return 1;
    
    return 0;
}

int is_valid_up(int i, int j)
{
    if(is_valid(i, j) == 0)
        return 0;
    
    if(grid[i][j] == 1 || grid[i][j] == 2)
        return 1;
    
    if(grid[i][j] == 4 || grid[i][j] == 7)
        return 1;
    
    return 0;
}

int is_valid_down(int i, int j)
{
    if(is_valid(i, j) == 0)
        return 0;
    
    if(grid[i][j] == 1 || grid[i][j] == 2)
        return 1;
    
    if(grid[i][j] == 5 || grid[i][j] == 6)
        return 1;

    return 0;
}

void bfs(int i, int j)
{
    if(!is_valid(i, j))
        return ;
        
    Node node;
    Queue que;

    init_queue(&que);

    dist[i][j] = 1;

    node._x = i;
    node._y = j;

    push(&que, node);
    vis[i][j] = 1;

    while(!empty(&que))
    {
        node = front(&que);
        pop(&que);

        if(dist[node._x][node._y] >= endo_len)
            continue;

        //printf("%d %d\n", dist[node._x][node._y], endo_len);
        if(is_valid_left(node._x, node._y) && is_valid_right(node._x, node._y-1) && !vis[node._x][node._y-1])
        {
            //printf("left\n");
            dist[node._x][node._y-1] = dist[node._x][node._y] + 1;
            vis[node._x][node._y-1] = 1;
            node._y--;
            push(&que, node);
            node._y++;
        }
    
        if(is_valid_right(node._x, node._y) && is_valid_left(node._x, node._y+1) && !vis[node._x][node._y+1])
        {
            //printf("right\n");
            dist[node._x][node._y+1] = dist[node._x][node._y] + 1;
            vis[node._x][node._y+1] = 1;
            node._y++;
            push(&que, node);
            node._y--;
        }
    
        if(is_valid_down(node._x, node._y) && is_valid_up(node._x+1, node._y) && !vis[node._x+1][node._y])
        {
            //printf("down\n");
            dist[node._x+1][node._y] = dist[node._x][node._y] + 1;
            vis[node._x+1][node._y] = 1;
            node._x++;
            push(&que, node);
            node._x--;
        }
    
        if(is_valid_up(node._x, node._y) && is_valid_down(node._x-1, node._y) && !vis[node._x-1][node._y])
        {
            //printf("up\n");
            dist[node._x-1][node._y] = dist[node._x][node._y] + 1;
            vis[node._x-1][node._y] = 1;
            node._x--;
            push(&que, node);
            node._x++;
        }
        //printf("llll %d\n", empty(&que));
    }
}

int main()
{
    int r, c, t;
    int i, j, ans;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d", &n, &m, &r, &c, &endo_len);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                scanf("%d", &grid[i][j]);
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }
        ans = 0;
        //printf("%d %d\n", r, c);
        if(endo_len > 0)
            bfs(r, c);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {   
               // printf("%d ", dist[i][j]);
                if(dist[i][j] <= endo_len)
                    ans++;
            }
            //printf("\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}
