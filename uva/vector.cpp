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

int main(){
    Vector<string> v;
    v.push_back("a");
    v.push_back("b");
    v.clear();
    v.push_back("a");
    
}