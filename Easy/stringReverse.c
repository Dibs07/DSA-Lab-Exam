#include <stdio.h>
#define max 100

void reverse(char *str)
{
    if (*str)
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    char s[max], b;
    int a = -1;
    printf("Enter string:");
    fgets(s, max, stdin);
    // for (int i = 0; s[i] != '\0'; i++)
    // {
    //     a++;
    // }
    //Reverse a string normally
    // for(int i=0;i<a/2;i++){
    //     b=s[i];
    //     s[i]=s[a-i-1];
    //     s[a-i-1]=b;
    // }
    printf("Reversed string:");
    reverse(s);
}