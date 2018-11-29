#include<bits/stdc++.h>

using namespace std;

#define MAX 100000

int status[1+MAX/32];
vector<int> prime;

int setBit(int n, int r){

    return n = n|(1<<r);
}

bool getBit(int n, int r){

    return (bool)(n&(1<<r));
}

void sieve(){

    for(int i = 3; i <= sqrt(MAX); i+=2){

        if(!getBit(status[i>>5], i&31)){

            for(int j = i*i; j<=MAX; j += 2*i){

                status[j>>5] = setBit(status[j>>5], j&31);
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i <= MAX; i+=2)
        if(!getBit(status[i>>5], i&31))
            prime.push_back(i);
}

int main(){

    sieve();
    int n;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n && n!=0){

        int tmp = n;
        if(n==1){

            cout << "0" << endl;
            continue;
        }
        vector<int> pfact;
        for(auto i: prime){

            if(i>n)break;
            if(n%i==0) pfact.push_back(i);
            while(n%i==0) n /= i;
        }
        if(n!=1) pfact.push_back(n);
        int phi = 1;
        for(auto i: pfact) phi *= i;
        phi = tmp/phi;

        for(auto i: pfact) phi *= i-1;
        cout << phi << endl;
    }
    return 0;
}
