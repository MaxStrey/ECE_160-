#include <stdio.h>
#include <float.h>

int main()
{
    printf("smallest float: %e \n", FLT_MIN);
    printf("largest float: %e \n", FLT_MAX);
    printf("smallest double: %e \n", DBL_MIN);
    printf("largest double: %e \n", DBL_MAX);
    printf("smallest long double: %Le \n", LDBL_MIN);
    printf("largest long double: %Le \n", LDBL_MAX);
}

