#include <stdio.h>

int main()
{
    int x = 3;
    int *p = (int*) &x;

    printf("Printing the address of x: %p\n", p);
    if (*p == 0x10)
    {
        printf("The underlying structure in the machine is little endian.\n");
    }
    else
    {
        printf("The underlying structure in the machine is big endian.\n");
    }
}