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
int make_permissions(int i, char *);
char *output_permissions(struct Filename *, int i);

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
        }
        else if (strcmp(input, "ls") == 0)
        {
            for (int i = 0; i < 20; i++)
            {
                if (strcmp(directory[i].name, "-") != 0)
                {
                    printf("%s\t%s\n", output_permissions(directory, i), directory[i].name);
                }
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
            strcpy(directory[find_file(directory, fname)].name, rename);
        }
        else if (strcmp(input, "chmod") == 0)
        {
            char fname[256];
            char nper[256];
            printf("Enter name of the file you want to change permissions: ");
            scanf("%256s", fname);
            while(getchar() != '\n');
            printf("Enter the changed permission: ");
            scanf("%256s", nper);
            while(getchar() != '\n');
            directory[find_file(directory, fname)].permissions = make_permissions(find_file(directory, fname), nper);
        }
        else if (strcmp(input, "rm") == 0)
        {
            char fname[256];
            printf("Enter name of the file you want to remove: ");
            scanf("%256s", fname);
            while(getchar() != '\n');
            directory[find_file(directory, fname)].permissions = -1;
            strcpy(directory[find_file(directory, fname)].name, "-"); 
        }
        else if (strcmp(input, "quit") == 0)
        {
            char dname[256];
            printf("Do you want to save to a file (y/n)?  ");
            scanf("%256s", dname);
            if (strcmp(dname, "y") == 0)
            {
                FILE *fp;
                fp = fopen( "file.txt" , "w" );
                for (int i = 0; i < 20; i++)
                {
                    char str[1024];
                    
                    if (strcmp(directory[i].name, "-") != 0)
                    {
                        size_t end = sprintf(str, "%s\t%s\n", output_permissions(directory, i), directory[i].name);
                        fwrite(str , 1 , end , fp );
                    }
                    
                
                }
                
                
                fclose(fp);
                break;
            }
            else if (strcmp(dname, "n") == 0)
            {
                break;
            }
        }  
    }
    return 0;
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
        if (strcmp(directory[i].name, fname) == 0)
        {
            return i;
        }
    }
    return 0;
}

int make_permissions(int i, char *nper)
{
    if (strcmp(nper, "x") == 0)
    {
        return 1;
    }
    if (strcmp(nper, "w") == 0)
    {
        return 2;
    }
    if (strcmp(nper, "wx") == 0)
    {
        return 3;
    }
    if (strcmp(nper, "r") == 0)
    {
        return 4;
    }
    if (strcmp(nper, "rx") == 0)
    {
        return 5;
    }
    if (strcmp(nper, "rw") == 0)
    {
        return 6;
    }
    if (strcmp(nper, "rwx") == 0)
    {
        return 7;
    }
    return 0;
}

char *output_permissions(struct Filename *directory, int i)
{
    if (directory[i].permissions == 1)
    {
        char *output = "x";
        return output;
    }
    if (directory[i].permissions == 2)
    {
        char *output = "w";
        return output;
    }
    if (directory[i].permissions == 3)
    {
        char *output = "wx";
        return output;
    }
    if (directory[i].permissions == 4)
    {
        char *output = "r";
        return output;
    }
    if (directory[i].permissions == 5)
    {
        char *output = "rx";
        return output;
    }
    if (directory[i].permissions == 6)
    {
        char *output = "rw";
        return output;
    }
    if (directory[i].permissions == 7)
    {
        char *output = "rwx";
        return output;
    }
    return 0;
}