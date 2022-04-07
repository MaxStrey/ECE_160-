#include <stdio.h>

/* returns x with the n bits that begin at position p set to the rightmost n bits of y
leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned ypart = (y & ~(~0 << n)) << (p+1-n); // rightmost n bits of y shifted to where they should be in x
    unsigned xmask = ~(~(~0 << n) << (p+1-n)); // mask that deletes the bits in x that will be replaced by ypart
    return (x & xmask) | ypart;
}

int main()
{

    unsigned result = setbits(17,2,2,10);

    printf("result %d \n",result);
}
