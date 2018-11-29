#include<bits/stdc++.h>

using namespace std;

#define MAX 10000

int status[1+MAX/32];
int prime[10000];


int setBit(int n, int x){

    return n = (n|(1<<x));
}

bool getBit(int n, int x){

    return (bool)(n&(1<<x));
}

void seive(){

    memset(status, 0, sizeof(status));

    for(int i = 3; i*i<=MAX; i+=2){

        if(!getBit(status[i>>5], i&31)){

            for(int j = i*i; j <= MAX; j+=2*i){

                status[j>>5] = setBit(status[j>>5], j&31);
            }
        }
    }

    int k = 1;
    prime[0] = 2;
    for(int i = 3; i<=MAX; i+=2)
    {
        if(!getBit(status[i>>5], i&31))
            prime[k++] = i;
    }
}

int main(){

    seive();
    int n;
    while(cin >> n && n!=0){

        int k = 0, sum;
        for(int i = 0; prime[i]<=n; i++){

            sum = prime[i];
            if(sum==n){

                k++;
                break;
            }

            for(int j = i+1; sum<n; j++){

                sum += prime[j];
            }

            if(sum==n)
                k++;
        }
        cout << k << endl;
    }
    return 0;
}
