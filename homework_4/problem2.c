#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strend(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    printf("%d\n", n);
    printf("%d\n", m);
    int counter = 0;
    int v = n - m;
    int true_v = v;
    int i = 0;
    while (v < n)
    {
        printf("%c\n", *(s + v));
        printf("  %c\n", *(t + i));
        printf("     %d\n", i);
        if (*(s + v) == *(t + i))
        {
            counter++;
        }
        i++;
        v++;
    }
    if (counter == true_v)
    {
        return 1;
    }
}


int main()
{
    char *s = "helloworld";
    char *t = "world";
    if (strend("Helloworld", "world") == 1)
    {
        printf("Hooray");
    }

    return 0;
}

