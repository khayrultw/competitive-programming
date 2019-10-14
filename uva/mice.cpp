#include <iostream>

using namespace std;

template<class T>
class Priority_Queue{
    T _arr[100000];
    int _size;
    public:
    Priority_Queue(){
        _size = 0;
    }

    bool empty(){
        return _size == 0;
    }

    void heapify(int x){
        int big, r, l = 2*x;
        big = x;
        r = l+1;
        if(l <= _size && _arr[l] < _arr[big])
            big = l;

        if(r <= _size && _arr[r] < _arr[big])
            big = r;
        
        if(big != x){
            swap(_arr[big], _arr[x]);
            heapify(big);
        }
    }

    void heapify1(int x){
        if(x <= 1)
            return ;
        
        if(_arr[x] < _arr[x/2]){
            swap(_arr[x/2], _arr[x]);
            heapify1(x/2);
        }
    }

    void push(T val){
        _size++;
        _arr[_size] = val;
        heapify1(_size);
    }

    T top(){
        return _arr[1];
    }

    void pop(){
        if(_size > 0)
        {   
            _arr[1] = _arr[_size];
            _size--;
            heapify(1);
        }
    }
};

typedef struct node{
    int x, y;
    node(int _x, int _y){
        x = _x;
        y = _y;
    }
    node(){}
} node;

bool operator<(const node &a, const node &b){
    return a.y < b.y;
}
int  n, d, t, e;
int graph[101][101];
int dist[101];

void dijstra(int x){
    dist[x] = 0;
    Priority_Queue<node> que;
    que.push(node(x, 0));
    while(!que.empty()){
        node tmp = que.top();
        //cout << tmp.x << " " << tmp.y << endl;
        que.pop();
        for(int i = 1; i <= n; i++){
            if(graph[tmp.x][i] != -1){
                if(dist[i] > dist[tmp.x]+graph[tmp.x][i]){
                    //cout << dist[i] << " " << dist[tmp.x]+graph[tmp.x][i] << endl;
                    dist[i] = dist[tmp.x]+graph[tmp.x][i];
                    que.push(node(i, dist[i]));
                }
            }
        }
    }
}

int main(){
    //freopen("out.txt", "w", stdout);
    int cas;
    cin >> cas;
    while(cas--){
        cin >> n >> d >> t;
        cin >> e;
        int a, b, c;

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                graph[i][j] = -1;

        for(int i = 0; i <= n; i++)
            dist[i] = 0x7fffffff;

        for(int i = 0; i < e; i++){
            cin >> a >> b >> c;
            graph[b][a] = c;
        }

        dijstra(d);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(dist[i] <= t)
                ans++;
        
        cout << ans << endl;
        if(cas) cout << endl;
    }
    return 0;
}