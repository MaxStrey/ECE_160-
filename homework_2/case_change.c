#include <stdio.h>
#include <stdlib.h>

int upper(int c)
{
                   if (c>= 'A' &c <= 'Z')
	  return c + 'a' - 'A';
                   else
                           return c;

}

int main()
{
	printf("%c\n", upper(97));
	return 0;
}




