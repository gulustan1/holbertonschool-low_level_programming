#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        int n;
        int lastd;
	
	srand(time(0));
    n = rand() - RAND_MAX / 2;
    lastd = n % 10;
	    printf("Last digit of %d is %d ", n, lastd);
	if (lastd > 5)
		printf("and is greater than 5\n");
    else if (lastd == 0)
        printf("and is 0\n");
    else
        printf("and is less than 6 and not 0\n");
	return (0);
}
