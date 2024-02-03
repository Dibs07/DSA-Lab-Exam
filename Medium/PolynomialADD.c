#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef, exp;
    struct Node *next;
} node;

node *hp1 = NULL, *hp2 = NULL, *hp3 = NULL;

void createPolynomial(node **hp, int c, int e)
{
    node *t = (node *)malloc(sizeof(node));
    if (t == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    t->coef = c;
    t->exp = e;
    t->next = NULL;
    if (*hp == NULL)
    {
        *hp = t;
    }
    else
    {
        node *temp = *hp;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
    }
}

void addition(node **hp1, node **hp2, node **hp3)
{
    if (*hp1 == NULL && *hp2 == NULL)
    {
        printf("Empty");
        return;
    }
    node *p = *hp1, *q = *hp2;
    while (p != NULL || q != NULL)
    {
        if (p->exp == q->exp)
        {
            // printf("%d",p->coef + q->coef);
            createPolynomial(&*hp3, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            createPolynomial(&*hp3, p->coef, p->exp);
            p = p->next;
        }
        else
        {
            createPolynomial(&*hp3, q->coef, q->exp);
            q = q->next;
        }
    }
}

void print(node **hp)
{
    node *temp = *hp;
    if (*hp == NULL)
    {
        printf("\nEmpty Polynomial\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coef, temp->exp);
        temp = temp->next;
    }
    // printf("%d\n", temp->coef);
}

int main()
{
    int n1, n2, c, e;
    printf("\nEnter the number of terms in Polynomial 1 : ");
    scanf("%d", &n1);
    printf("\nEnter the number of terms in Polynomial 2 : ");
    scanf("%d", &n2);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter Coefficient: ");
        scanf("%d", &c);
        printf("Enter Exponent: ");
        scanf("%d", &e);
        createPolynomial(&hp1, c, e);
    }
    print(&hp1);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter Coefficient: ");
        scanf("%d", &c);
        printf("Enter Exponent: ");
        scanf("%d", &e);
        createPolynomial(&hp2, c, e);
    }
    print(&hp2);
    addition(&hp1,&hp2,&hp3);
    printf("\nSum of two polynomials is : \n");
    print(&hp3);
}