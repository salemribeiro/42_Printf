#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	char a;
	unsigned char b;
	char c;

	a = 12;
//	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
//	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
//	printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
//	ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n0\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("%s\n", "salem freitas ribeiro junior");
	return (0);

}
