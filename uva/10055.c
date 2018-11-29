#include<stdio.h>
int main(){
   long long h,p,d;
    while(scanf("%lld%lld",&h,&p)!=EOF){
        d=p-h;
        printf("%lld\n",d);
    }
    return 0;
}

