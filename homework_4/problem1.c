#include <stdio.h>

int main()
{
   int test_var = *(unsigned char *)&(const int){1};

   if (test_var == 1) 
   {
        printf("this machine is little-endian\n");
   } else 
   {
        printf("this machine is big-endian\n");
   }
}