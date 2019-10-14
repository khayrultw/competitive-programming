#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class Vector{
    private:
        T _buffer[10000];
        unsigned int _size;
    public:
        Vector();
        ~Vector();
        void push_back(T data);
        void pop_back();
        void clear();
        unsigned int size();
        T operator[](unsigned int index);
        T* begin();
        T* end();
};

template<class T>
T* Vector<T>::begin(){
    return &_buffer[0];
}

template<class T>
T* Vector<T>::end(){
    return &_buffer[_size];
}


template<class T>
Vector<T>::Vector(){
    _size = 0;
}

template<class T>
void Vector<T>::push_back(T data){
    _buffer[_size] = data;
    _size++;
}

template<class T>
void Vector<T>::pop_back(){

    if(_size>0)
        _size--;
}

template<class T>
void Vector<T>::clear(){
    _size = 0;
}

template<class T>
T Vector<T>::operator[](unsigned int index){
    return _buffer[index];
}

template<class T>
Vector<T>::~Vector(){

}

template<class T>
unsigned int Vector<T>::size(){
    return _size;
}

template<class X>
class Queue{
    X arr[10000];
    int _front, _back;
    public:
        Queue(){
            _front = _back = -1;
        }
        void push(X v){
            _back = (_back+1)%10000;
            arr[_back] = v;
        } 

        X front(){
            return arr[(_front+1)%10000];
        }

        void pop(){
            if(!empty())
                _front = (_front+1)%10000;
        }

        bool empty(){
            return _front == _back;
        }
};

Vector<int> graph[50];
Vector<int> node;

int indexof(int x){
    for(int i = 0; i < node.size(); i++){
        if(node[i] == x)
            return i;
    }
    node.push_back(x);
    return node.size()-1;
}

int ttl[50];
bool vis[50];

void bfs(int st, int tl){
    vis[st] = true;
    Queue<int> que;
    ttl[st] = tl;
    que.push(st);

    while(!que.empty()){
        int u = que.front();
        que.pop();
        if(ttl[u]>0){
            for(int i = 0; i < graph[u].size(); i++){
                int x = graph[u][i];
                if(!vis[x]){
                    que.push(x);
                    ttl[x] = ttl[u]-1;
                    vis[x] = true;
                    //cout << node[u] << " " << ttl[u] << endl;
                }
            }
        }
    }
}

int main(){
    int nc, cas = 0;
    while(cin >> nc && nc != 0){
        int a, b;
        for(int i = 0; i < nc; i++){
            cin >> a >> b;
            a = indexof(a);
            b = indexof(b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int tmp = node.size();
        while(cin >> a >> b && (a != 0 || b != 0)){
            for(int i = 0; i < 50; i++){
                vis[i] = false;
            }
            bfs(indexof(a), b);
            int ans = 0;
            for(int i = 0; i < tmp; i++){
                if(vis[i])
                    ans++;
            }
            cout << "Case " << ++cas << ": "; 
            cout << tmp-ans;
            cout << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
        }
        for(int i = 0; i < 50; i++)
            graph[i].clear();
        node.clear();
    }
    return 0;
}