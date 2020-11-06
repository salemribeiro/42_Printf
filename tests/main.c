#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	char a;
	unsigned char b;
	char c;

	a = 12;
	printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	return (0);
}
