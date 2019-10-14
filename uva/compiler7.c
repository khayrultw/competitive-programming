#include<stdio.h>
#include<string.h>
#include<ctype.h>

char keyword[35][15]={
    "auto","double","int","struct","break","else","long", "false",
    "switch","case","enum","register","typedef","char", "true",
    "extern","return","union","const","float","short", "bool"
    "unsigned","continue","for","signed","void","default",
    "goto","sizeof","voltile","do","if","static","while"
};

int isOperator(char *ch)
{
    if(strlen(ch) != 1)
        return 0;

    if(ch[0] == '+' || ch[0] == '-' || ch[0] == '*' ||
        ch[0] == '/' || ch[0] == '>' || ch[0] == '<' ||
        ch[0] == '=')
        return (1);
    return (0);
}

int isKeyword(char *str){
    for(int i = 0; i < 35; i++){
        if(strcmp(keyword[i], str) == 0)
            return 1;
    }
    return 0;
}

int isIden(char *str){

    if(!isalpha(str[0]) || !str[0] == '_')
        return 0;

    for(int i = 1; i < strlen(str); i++)
        if(!isalnum(str[i]))
            return 0;

    return 1;
}


int isFloat(char *str){

    int len = strlen(str);
    if(str[0] == '0' && str[1] != '.')
        return 0;

    if(str[len-1] == '.' || str[0] == '.')
        return 0;

    int dot = 0, d = 0;

    for(int i = 0; i < len; i++){
        if(isdigit(str[i]))
            d++;
        if(str[i] == '.')
            dot = 1;
    }
    if(dot != 1 || d != len-1)
        return 0;

    return 1;
}

int isInt(char *str){
    int len = strlen(str);

    if(len > 1 && str[0] == '0')
        return 0;

    for(int i = 0; i < len; i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }

    return 1;
}
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
    if(isKeyword(input))
        printf("%s is a keyword\n", input);
    else if(isIden(input))
        printf("%s is a identifier\n", input);
    else if(isOperator(input))
        printf("%s is a operator\n", input);
    else if(isFloat(input) || isInt(input))
        printf("%s is a constant\n", input);
    else
        printf("Invalid input\n");
}