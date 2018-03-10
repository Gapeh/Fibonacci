
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "Fibonacci.h"


HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q)
{


}

HugeInteger *hugeDestroyer(HugeInteger *p)
{
    free(p->digits);
}

HugeInteger *parseString(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    struct HugeInteger *p = malloc(sizeof(struct HugeInteger));
    int x;
    int numLength = strlen(str);
    p->digits = malloc(sizeof(int*) * numLength);
    if (p->digits == NULL)
    {
        return NULL;
    }
    printf("%i \n", numLength);
    printf("%i \n", atoi(str));
    p->length = numLength;
    for(x = 0; x < numLength ; x++)
    {
        printf("adding %i to p->digits\n", str[x] - 48);
        p->digits[x] = str[x] - 48;
    }
    printf("\n");
    return p;
}

HugeInteger *parseInt(unsigned int n)
{
    if (n == NULL)
    {
        return NULL;
    }

    struct HugeInteger *p = malloc(sizeof(struct HugeInteger));
    int x;
    int numLength = floor(log10(abs(n))) + 1;
    p->digits = malloc(sizeof(int*) * numLength);
    if (p->digits == NULL)
    {
        return NULL;
    }
    printf("%i \n", numLength);
    printf("%i \n", n);
    p->length = numLength;
    for(x = numLength - 1; x > 0; x--)
    {

        printf("adding %i to p->digits\n", n % 10);
        p->digits[x - numLength] = n % 10;
        n /= 10;
    }
    printf("\n");
    return p;
}

unsigned int *toUnsignedInt(HugeInteger *p)
{
    int x, y;
    unsigned int output = 0;
    if (p->length > 10)
    {
        return NULL;
    }
    else if (p-> length == 10)
    {
        if (p->digits[9] > 4)
        {
            return NULL;
        }
        else if (p->digits[8] > 2)
        {
            return NULL;
        }
        else if (p->digits[7] > 9)
        {
            return NULL;
        }
        else if (p->digits[6] > 4)
        {
            return NULL;
        }
        else if (p->digits[5] > 9)
        {
            return NULL;
        }
        else if (p->digits[4] > 6)
        {
            return NULL;
        }
        else if (p->digits[3] > 7)
        {
            return NULL;
        }else if (p->digits[2] > 2)
        {
            return NULL;
        }
        else if (p->digits[1] > 9)
        {
            return NULL;
        }
        else if (p->digits[0] > 5)
        {
            return NULL;
        }
    }
    int multiplesOf10 = 1;

    for(x = 0; x > 11; x++)
    {
        output += p->digits[x] * multiplesOf10;
        multiplesOf10 *= 10;
    }
    return output;
}

HugeInteger *fib(int n)
{

}

double difficultyRating(void)
{

}

double hoursSpent(void)
{

}
