#include <stdio.h>
#include <stdint.h>
#include <ft_printf.h>

int main()
{
	char a;
	unsigned char b;
	char c;

	a = -25;
	b = 25;
	c = (char)(unsigned char)a;
	printf("%c%c%c\n\n", a, b, c);
	ft_printf("%c%c%c\n", a, b, c);
	return (0);
}
