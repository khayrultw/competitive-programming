#include<stdio.h>
long long gcdf(long long a,long long b);
int main(){
   long long P[2][2],S[2][2],i,j,gcd,n,k;
    scanf("%lld",&n);
    while(n--){
        k=1;
        for(i=0;i<2;i++){
            scanf("%lld%lld",&S[i][0],&S[i][1]);
            scanf("%lld%lld",&P[i][0],&P[i][1]);
        }
        gcd=P[0][0];
        j=1;
        for(i=0;i<2;i++) {
            for(;j<2;j++)
                gcd=gcdf(gcd,P[i][j]);
            j=0;
        }
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                if(S[i][j]%gcd!=0){
                k=0;
                i=3;
                }
            }
        }
        if(k)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
long long gcdf(long long a,long long b){
    long long tmp,k=1;
    while(k){
        tmp=b%a;
        if(tmp!=0){
            b=a;
            a=tmp;
        }
        else
        k=0;
    }
    return a;
}
