#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strend(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    int counter = 0;
    int v = n - m;
    int true_v = v;
    int i = 0;
    while (v < n)
    {
        if (*(s + v) == *(t + i))
        {
            counter++;
        }
        i++;
        v++;
    }
    if (counter == m)
    {
        return 1;
    }
    return 0;
}


int main()
{
    char *s = "hellorld";
    char *t = "world";
    printf("%d\n", strend(s, t));
    
    return 0;
}

