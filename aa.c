#include <stdio.h>
#include <string.h>

    char *names[] = {"Jhon", "Robin", "Mark", NULL};
int search(char *p[], char *names);
int main(void)
{
    if (search(names, "Sushant") != -1)
    {
        printf("Sushant is in this list");
    }
    else
    {
        printf("Sushant is not in this list.");
    }
    return 0;
}

int search(char *p[], char *name)
{
    register int t;
    for (t = 0; p[t]; t++)
    {
        if (!strcmp(p[t], name))
        {
            return t;
        }
        else
        {
            return -1;
        }
    }
}