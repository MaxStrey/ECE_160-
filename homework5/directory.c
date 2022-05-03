#include <stdio.h>
#include <string.h>

struct Filename
{
    char name[256];
    int permissions;
}


int main()
{
    struct Filename *p = (struct Filename *) malloc(20 * sizeof(struct Filename));
    struct Filename newDirectory[20];
    for (int i=0; i<20; i++) {
        newDirectory[i] = (struct Filename) {"-", -1};
    }
    p = &newDirectory;
    
    char input[256];
    while(1) 
    {
        scanf("%256s", input);
        while (getchar());
        if (strcmp(input, "touch"))
        {
            char dname[256];
            printf("Enter name of destination file: ");
            scanf("%256s", dname);
            while(getchar());
            for ()
        }
    }

}