#include <stdio.h>

int main()
{
	int a = 0x93;
	int b = 0xc3;
	int c;

	c = (int)(char)a;
	printf("%c\n", c);
	c = (int)(char)b;
	printf("%c\n",c);


	return (0);
}
