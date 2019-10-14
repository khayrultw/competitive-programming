#include<stdio.h> ///2
#include<ctype.h>
#include<string.h>

int isVowel(char ch){

    if(ch == 'A' || ch == 'E' || ch == 'I')
        return 1;

    else if(ch == 'O' || ch == 'U' || ch == 'a')
        return 1;

    else if(ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;

    else
    {
        if(isalpha(ch) && ch != ' ')
            return 0;
    }
    return -1;
}

int main(){
    char str[100];
    int vowel, cons;
    vowel = cons = 0;

    int i = 0; /// 2
    while(1){
        str[i] = getchar();
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
    }
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(isVowel(str[i]) == 1)
            vowel++;
        if(isVowel(str[i]) == 0)
            cons++;
    }

    int c, v;
    c = v = 0;
    char consen[100], vowsen[100];
    for(int i = 0; i < strlen(str); i++){

        if(isVowel(str[i]) == 1){
            while(str[i] != ' ' && i < strlen(str))
                vowsen[v++] = str[i++];
            vowsen[v++] = ' ';
        }
        else if(isVowel(str[i]) == 0){
            while(str[i] != ' ' && i < strlen(str))
                consen[c++] = str[i++];
            consen[c++] = ' ';
        }
        /// 2
    }
    printf("Vowels: %d\nConsonant: %d\n", vowel, cons);
    char vowels[] = "AaEeIiOoUu";
    printf("Existed vowels: ");
    for(int i = 0; i < strlen(vowels); i+=2){
        for(int j = 0; j < strlen(str); j++){
            if(vowels[i] == str[j] || vowels[i+1] == str[j]){
                printf("%c", vowels[i]);
                break;
            }
        }
    }

    consen[c] = vowsen[v] = '\0';
    printf("\n%s\n%s\n", consen, vowsen);
    return 0;
}
