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
    return &_buffer[_size-1];
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
Vector<int> graph[30];
bool vis[30];

void dfs(int u){
    vis[u] = true;
    for(int i = 0; i < graph[u].size(); i++){
        if(!vis[graph[u][i]]){
            dfs(graph[u][i]);
        }
    }
}

int main(){
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cin.ignore();
        //cin.ignore();
        int n = str[0]-'A';
        while(getline(cin, str)){
            //cout << str << endl;
            if(str == "")
                break;
            int a, b;
            a = str[0]-'A';
            b = str[1]-'A';
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans = 0;
        for(int i = 0; i <= n; i++) vis[i] = false;
        for(int i = 0; i <= n; i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        cout << ans << endl;
        if(t)
            cout << endl;
        for(int i = 0; i < 30; i++)
            graph[i].clear();

    }
    return 0;
}


