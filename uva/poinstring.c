/*5 number.pointer diye kora ache tui string babohar koris*/
#include<stdio.h>
int main(){
    int i,count,j;
    char *np,*sp,*p;
    p=(char*)malloc(2);
    np=(char*)malloc(2);
    sp=(char*)malloc(2);
    scanf("%s",p);
    for(i=0,j=0;*p!='\0';p++){
        if(*p>=48 && *p<=57){
            *(np+i)=*p;
            i++;
        }
        else{
            *(sp+j)=*p;
            j++;
        }
    }
    *(np+i)='\0';
    *(sp+j)='\0';
    printf("%s\n",np);
    printf("%s\n",sp);
    return 0;
}
