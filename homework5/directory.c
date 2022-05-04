#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Filename
{
    char name[256];
    int permissions;
};
int find_empty(struct Filename *);

int main()
{
    struct Filename *directory = (struct Filename *) malloc(20 * sizeof(struct Filename));
    //struct Filename newDirectory[20];
    for (int i=0; i<20; i++) 
    {
        strcpy(directory[i].name, "-");
        directory[i].permissions = -1;
    }
    //p = &directory;

    printf("%s\n", directory[0].name);
    
    char input[256];
    while(1) 
    {
        scanf("%256s", input);
        while (getchar() != '\n');
        if (strcmp(input, "touch") == 0)
        {
            int i;
            printf("hi\n");
            char dname[256];
            printf("Enter name of destination file: ");
            scanf("%256s", dname);
            while(getchar() != '\n');
            strcpy(directory[find_empty(directory)].name, dname);
            printf("%s\n", directory[0].name);
            
            
        }
        
    }

}

int find_empty(struct Filename *directory)
{
    for (int i = 0; i < 20; i++)
    {
        if (directory[i].permissions == -1)
        {
            return i;
        }

    }
    return 0;

}