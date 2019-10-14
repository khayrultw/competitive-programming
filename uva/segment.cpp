#include <bits/stdc++.h>

using namespace std;

struct node{
    int a, b, c;
};

const int M = 100001;
node tree[2*M];
int n,q;

void build(){
    for(int i = n-1; i > 0; i >>= 1){
        tree[i].a = tree[i<<1].a + tree[i<<1 | 1].a;
    }
}
int main(){
    cin >> n >> q;
    for(int i = n; i < 2*n; i++)
    {
        tree[i].b = tree[i].c = 0;
        tree[i].a = 1;
    }
    build();
}