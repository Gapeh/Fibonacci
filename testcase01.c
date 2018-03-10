#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Fibonacci.h"

HugeInteger *hugeDestroyer(HugeInteger *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    free(p->digits);
    return NULL;
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
 //   printf("%i \n", numLength);
  //  printf("%i \n", atoi(str));
    p->length = numLength;
    for(x = 0; x < numLength ; x++)
    {
     //   printf("adding %i to p->digits at spot %i\n", str[x] - 48, x);
        p->digits[x] = str[numLength - x - 1] - 48;
    }
   // printf("\n");
    return p;
}

// print a HugeInteger (followed by a newline character)
void hugePrint(HugeInteger *p)
{
	int i;

	if (p == NULL || p->digits == NULL)
	{
		printf("(null pointer)\n");
		return;
	}

	for (i = p->length - 1; i >= 0; i--)
		printf("%d", p->digits[i]);
	printf("\n");
}
HugeInteger *parseInt(unsigned int n)
{
    if (n == NULL && n != 0)
    {
        return NULL;
    }
    struct HugeInteger *p = malloc(sizeof(struct HugeInteger));
    int x, numLength;
    unsigned int numberLengthPlaceholder = n;
    x = 0;
    while (numberLengthPlaceholder > 0)
    {
        x++;
        numberLengthPlaceholder /= 10;
      //  printf("Value is %u\n", numberLengthPlaceholder);
      //  printf("X Value is %i\n", x);
    }
    if (n == 0)
    {
        p->digits = malloc(sizeof(int*));
        p->length = 1;
        p->digits[0] = 0;
        return p;

    }
    numLength = x;
    p->digits = malloc(sizeof(int*) * numLength);
    if (p->digits == NULL)
    {
        return NULL;
    }
   // printf("%i \n", numLength);
   // printf("%u \n", n);
    p->length = numLength;
   // printf("%i Ld\n", p->length);
    for(x = numLength - 1 ; x >= 0; x--)
    {

      //  printf("adding %i to p->digits at spot %i\n", (n % 10), numLength - x - 1);
        p->digits[ numLength - x - 1] = (n % 10);
        n /= 10;
    }
    for(x = 0 ; x < numLength; x++)
    {

   //     printf("%i : %i \n", x, p->digits[x]);
    }
   // printf("\n");
    return p;
}
unsigned int *toUnsignedInt(HugeInteger *p)
{
    int x, y;
    unsigned int *output = 0;
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
int main(void)
{
    unsigned int *temp;
	HugeInteger *p;

	hugePrint(p = parseString("12345"));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseString("354913546879519843519843548943513179"));
	temp = toUnsignedInt(p);
	if (temp == NULL)
		printf("Good work.\n");
	else
		printf("Uh oh...\n");
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseString(NULL));
	temp = toUnsignedInt(p);
	if (temp == NULL)
		printf("Good work.\n");
	else
		printf("Uh oh...\n");
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(246810));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(0));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(INT_MAX));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	hugePrint(p = parseInt(UINT_MAX));
	printf("%u\n", *(temp = toUnsignedInt(p)));
	free(temp);
	hugeDestroyer(p);

	return 0;
}
