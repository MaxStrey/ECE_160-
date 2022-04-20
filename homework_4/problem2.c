#include <stdio.h>
#include <string.h>

int main()
{
    char *str = "worldhelloworld";
    char *nstr = "world";
    int n = strlen(str);
    int m = strlen(nstr);
    printf("%d\n", n);
    printf("%d\n", m);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {       
        for (int j = 0; j < m; j++)
        {
            if (j == i && j == i - m)
            {
                counter++;
                if (counter == m)
                {
                    printf("nstr is at the end of str\n");
                }
            } 
        }
    }
    return 0;
}