#include <stdio.h> ///6
#include <ctype.h>
#include <string.h>

int isCharVar(char *str){
    if(str[0] != 'c' || str[1] != 'h' || str[2] != '_')
        return 0;
    for(int i = 3; i < strlen(str); i++){
        if(!isalnum(str[i]))
            return 0;
    }
    return 1;
}

int isBinaryVar(char *str){
    if(str[0] != 'b' || str[1] != 'n' || str[2] != '_')
        return 0;
    for(int i = 3; i < strlen(str); i++){
        if(!isalnum(str[i]))
            return 0;
    }
    return 1;
}

int isBinary(char *str){
    if(str[0] != '0') /// 6
        return 0;
    for(int i = 1; i < strlen(str); i++){
        if(str[i] != '0' && str[i] != '1')
            return 0;
    }
    return 1;
}

int main(){
    char input[100]; ///6
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
    if(isBinary(input))
        printf("%s is a binary number\n", input);
    else if(isBinaryVar(input))
        printf("%s is a binary variable\n", input);
    else if(isCharVar(input))
        printf("%s is a character variable\n", input);
    else
        printf("Invalid input\n");
}
