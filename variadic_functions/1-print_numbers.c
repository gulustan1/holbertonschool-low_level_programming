#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Sayıları yan yana yazdırır, aralarına ayırıcı koyar.
 * @separator: Sayılar arasında yazdırılacak olan string.
 * @n: Fonksiyona gönderilen sayı adedi.
 * @...: Yazdırılacak olan tam sayılar.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int i;

	va_start(nums, n);

	for (i = 0; i < n; i++)
	{
		/* Sıradaki sayıyı yazdır */
		printf("%d", va_arg(nums, int));

		/* Eğer ayırıcı varsa ve son eleman değilsek ayırıcıyı yazdır */
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(nums);
}

