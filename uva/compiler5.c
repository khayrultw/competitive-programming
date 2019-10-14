#include<stdio.h> ///5
#include<ctype.h>
#include<string.h>

int isFloatVariable(char *str){

    if(str[0] < 'A' || str[0] > 'z')
        return 0;

    if(str[0] > 'Z' && str[0] < 'a')
        return 0;

    if(str[0] > 'H' && str[0] < 'O')
        return 0;

    if(str[0] > 'h' && str[0] < 'o')
        return 0;

    for(int i = 1; i < strlen(str); i++)
        if(!isalnum(str[i]))
            return 0;

    return 1;
}

int isDouble(char *str){ ///5
    if(str[0] == '0' && str[1] != '.')
        return 0;
    int dot, d = 0;
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i]))
            d++;
        if(str[i] == '.')
            dot = 1;
    }
    if(dot != 1 && d != strlen(str)-1)
        return 0;

    int i = 0;
    while(str[i++] != '.');
    if(strlen(str)-i < 3)
        return 0;

    return 1;

}

int isFloat(char *str){ /// 5

    if(str[0] == '0' && str[1] != '.')
        return 0;
    int dot, d = 0;
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i]))
            d++;
        if(str[i] == '.')
            dot = 1;
    }
    if(dot != 1 && d != strlen(str)-1)
        return 0;

    int i = 0;
    while(str[i++] != '.');
    if(strlen(str)-i != 2)
        return 0;

    return 1;

}

int main(){ /// 5
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

    if(isFloatVariable(input))
        printf("%s is a float variable.\n", input);

    else if(isFloat(input))
        printf("%s is a float number.\n", input);

    else if(isDouble(input))
        printf("%s is a double number.\n", input);
    else
        printf("%s is undefined\n", input);
}
