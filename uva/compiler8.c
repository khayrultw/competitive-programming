#include<stdio.h> /// 8
#include<string.h>
#include<ctype.h>

char keyword[35][10]={
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
        return (0);
    return (1);
}

int isKeyword(char *str){
    for(int i = 0; i < 35; i++){
        if(strcmp(keyword[i], str))
            return 1;
    }
    return 0;
}
/// 8
int isIden(char *str){
    if(!isalpha(str[0]) && !str[0] == '_')
        return 0;
    for(int i = 1; i < strlen(str); i++)
        if(!isalnum(str[i]))
            return 0;
    return 1;
}

int isInt(char *str){
    for(int i = 0; i < strlen(str); i++)
        if(!isdigit(str[i]))
            return 0;

    if(str[0] == '0' && strlen(str) > 1)
        return 0;

    return 1;
}

int isFloat(char *str){ /// 8

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

int main(){
     /// 8
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
        printf("Keyword\n");
    else if(isiden(input))
        printf("Identier\n");
    else if(isOperator(input))
        printf("Operator\n");
    else if(isFloat(input))
        printf("Float\n");
    else
        printf("Invalid input\n");
}
