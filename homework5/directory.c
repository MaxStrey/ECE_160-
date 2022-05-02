#include <stdio.h>

struct Filename
{
    char name[256];
    int permissions;
}

struct Filename *p = (struct Filename *) malloc(20 * sizeof(struct Filename))
//p[1] = *(p + sizeof(struct Filename)*1)