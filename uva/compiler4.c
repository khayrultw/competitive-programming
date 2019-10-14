#include<stdio.h> /// 4
#include<ctype.h>
#include<string.h>

int isIntVariable(char *str){

    if(str[0] < 'I' || str[0] > 'n')
        return 0;

    if(str[0] > 'N' && str[0] < 'i')
        return 0;

    for(int i = 1; i < strlen(str); i++)
        if(!isalnum(str[i]))
            return 0;

    return 1;
}

int isShortInt(char *str){
    for(int i = 0; i < strlen(str); i++)
        if(!isdigit(str[i]))
            return 0;

    if(str[0] == '0' || strlen(str) > 4)
        return 0;

    return 1;
}
 /// 4
int isLongInt(char *str){
    for(int i = 0; i < strlen(str); i++)
        if(!isdigit(str[i]))
            return 0;

    if(str[0] == '0' && strlen(str) < 5)
        return 0;

    return 1;
}
/// 4
int main(){
    char input[100];
    int i = 0;
    while(1){
        input[i] = getchar();
        if(input[i] == '\n')
        {
            input[i] = '\0';
            break;
        }
        i++;
    }
    input[i] = '\0';

    if(isIntVariable(input))
        printf("%s is a integer variable.\n", input);

    else if(isShortInt(input))
        printf("%s is a short integer.\n", input);

    else if(isLongInt(input))
        printf("%s is a long integer.\n", input);
    else
        printf("%s is undefined\n", input);
}
