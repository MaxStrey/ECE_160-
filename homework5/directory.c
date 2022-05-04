#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Filename
{
    char name[256];
    int permissions;
};
int find_empty(struct Filename *);
int find_file(struct Filename *, char *);

int main()
{
    struct Filename *directory = (struct Filename *) malloc(20 * sizeof(struct Filename));
    for (int i=0; i<20; i++) 
    {
        strcpy(directory[i].name, "-");
        directory[i].permissions = -1;
    }
    
    char input[256];
    while(1) 
    {
        scanf("%256s", input);
        while (getchar() != '\n');
        if (strcmp(input, "touch") == 0)
        {
            int i;
            char dname[256];
            printf("Enter name of destination file: ");
            scanf("%256s", dname);
            while(getchar() != '\n');
            strcpy(directory[find_empty(directory)].name, dname);
            directory[find_empty(directory)].permissions = 7;
            for (int j = 0; j < 20; j++)
            {
                printf("%s\n", directory[j].name);
                printf("%d\n", directory[j].permissions);
            }

        }
        else if (strcmp(input, "ls") == 0)
        {
            for (int j = 0; j < 20; j++)
            {
                printf("%s\n", directory[j].name);
            }
        }
        else if (strcmp(input, "mv") == 0)
        {
            char fname[256];
            printf("Enter name of the file you want to rename: ");
            scanf("%256s", fname);
            while(getchar() != '\n');
            char rename[256];
            printf("Enter name of renamed file: ");
            scanf("%256s", rename);
            while(getchar() != '\n');
            strcpy(directory[find_file(directory, fname)-1].name, rename);
            for (int j = 0; j < 20; j++)
            {
                printf("%s\n", directory[j].name);
                printf("%d\n", directory[j].permissions);
            }
        }
        else if (strcmp(input, "chmod") == 0)
        {
            char fname[256];
            printf("Enter name of the file you want to change permissions: ");
            scanf("%256s", fname);
            while(getchar() != '\n');
            directory[find_file(directory, fname)-1].permissions = -1;
            strcpy(directory[find_file(directory, fname)-1].name, "-"); 
        }
        else if (strcmp(input, "rm") == 0)
        {
            char fname[256];
            printf("Enter name of the file you want to remove: ");
            scanf("%256s", fname);
            while(getchar() != '\n');
            directory[find_file(directory, fname)-1].permissions = -1;
            strcpy(directory[find_file(directory, fname)-1].name, "-"); 
            for (int j = 0; j < 20; j++)
            {
                printf("%s\n", directory[j].name);
                printf("%d\n", directory[j].permissions);
            }
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

int find_file(struct Filename *directory, char *fname)
{
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(directory[i].name, fname))
        {
            return i;
        }
    }
    return -1;
}

char make_permissions(int i, struct Filename *directory, char *per)
{
    char *per;
    if (directory[i].permissions == 1)
    {
        char *outputr = "x";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 2)
    {
        char *outputr = "w";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 3)
    {
        char *outputr = "wx";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 4)
    {
        char *outputr = "r";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 5)
    {
        char *outputr = "rx";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 6)
    {
        char *outputr = "rw";
        return outputr;
    }
    char *per;
    if (directory[i].permissions == 7)
    {
        char *outputr = "rwx";
        return outputr;
    }
}

int find_permissions()