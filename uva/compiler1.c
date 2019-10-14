///  1.
#include<stdio.h>
#include<ctype.h>

int main(){
    char str[100], letters[100], digits[100], others[100];
    int word, letter, digit, other;
    word  = letter = digit = other = 0;

    int i = 0;
    while(1){
        str[i] = getchar();
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
    }
    int flag = 0;
    int l, d, o;
    l = d = o = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(isalpha(str[i])){
            flag = 1;
            letter++;
            letters[l] = str[i];
            l++;
        }
        else if(isalnum(str[i]))
        {
            digit++;
            digits[d] = str[i];
            d++;
        }
        // 1.
        else
        {
            other++;
            others[o] = str[i];
            o++;
        }

        if(flag && (str[i] == ' ' ||  str[i+1] == '\0'))
        {
            flag = 0;
            word++;
        }
    }
    letters[l] = digits[d] = others[o] = '\0';
    printf("Number of word: %d\n", word);
    printf("Number of letter: %d\n", letter);
    printf("Number of digit: %d\n", digit);
    printf("Number of other character: %d\n", other);
    printf("Letters: %s\n", letters);
    printf("digits: %s\n", digits);
    printf("others: %s\n", others);
    return 0;
}
