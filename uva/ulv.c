#include<stdio.h>
int main() {
    int i,j,n;
    printf("n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        for(j=1;j<=2*n-1;j++) {
            if(i+j==n+1 || j==i+n-1)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
