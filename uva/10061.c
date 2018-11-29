#include<stdio.h>
long long fac(long long n);
int main(){
    long long N,B,f,c,d,i;
    while(scanf("%lld%lld",&N,&B)!=EOF){
        c=0; d=0;
        f=fac(N);
        while(f){
            if(f%B==0)
                c++;
            f=f/B;
            d++;
        }
        printf("%lld %lld\n",c,d);
    }
    return 0;
}
long long fac(long long n){
    if(n==0)
        return 1;
    return n*fac(n-1);
}