#include <stdio.h>

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixtoPostfix(char s[])
{
    int i = 0, j = 0, k = 0;
    char stack[50];
    char res[50];
    for (i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            res[j++] = c;
        }
        else if (c == '(')
        {
            stack[k++] = c;
        }
        else if (c == ')')
        {
            while (stack[--k] != '(')
            {
                res[j++] = stack[k];
            }
        }
        else
        {
            while (k > 0 && prec(c) < prec(stack[k - 1])|| prec(c)==prec(stack[k-1]))
            {
                res[j++] = stack[--k];
            }
            stack[k++] = c;
        }
    }
    while (k > 0)
    {
        res[j++] = stack[--k];
    }
    res[j] = '\0';
    printf("%s", res);
}

int main()
{
     printf("Enter the expression : ");
    char exp[50];
     scanf("%s", exp);
    infixtoPostfix(exp);
}