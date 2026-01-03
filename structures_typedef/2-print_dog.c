#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: struct dog to print
 */
void print_dog(struct dog *d)
{
	/* 1. Əgər strukturun özü yoxdursa (NULL), heç nə etmə və çıx */
	if (d == NULL)
		return;

	/* 2. Adı yoxla və çap et */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* 3. Yaşı çap et (%f float üçün istifadə olunur) */
	printf("Age: %f\n", d->age);

	/* 4. Sahibini yoxla və çap et */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
