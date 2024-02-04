#include <stdio.h>
#include <stdlib.h>

typedef struct Rational
{
    int num, den;
} rat;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

rat *simplify(rat *r)
{
    int d = gcd(r->num, r->den);
    r->num /= d;
    r->den /= d;
    if (r->num == 0)
    {
        r->den = 0;
    }
    if (r->den < 0)
    {
        r->num = -r->num;
        r->den = -r->den;
    }
    return r;
}

rat *addRat(rat *r1, rat *r2)
{
    rat *sum = (rat *)malloc(sizeof(rat));
    sum->num = r1->num * r2->den + r1->den * r2->num;
    sum->den = r1->den * r2->den;
    return simplify(sum);
}

rat *multiRat(rat *r1, rat *r2)
{
    rat *mul = (rat *)malloc(sizeof(rat));
    mul->num = r1->num * r2->num;
    mul->den = r1->den * r2->den;
    return simplify(mul);
}

void ratPrint(rat *r)
{
    if (r->num == 0)
    {
        printf("%d", r->num);
    }
    else
        printf("%d/%d\n", r->num, r->den);
}

int main()
{
    rat *a = (rat *)malloc(sizeof(rat));
    printf("Enter numerator  and denominator for first fraction:\n");
    scanf("%d%d", &a->num, &a->den);
    ratPrint(a);
    rat *b = (rat *)malloc(sizeof(rat));
    printf("Enter numerator  and denominator for second fraction:\n");
    scanf("%d%d", &b->num, &b->den);
    ratPrint(b);
    printf("\nAddition of fractions is : ");
    ratPrint(addRat(a, b));
    printf("\nMultiplication of fractions is : ");
    ratPrint(multiRat(a, b));
}