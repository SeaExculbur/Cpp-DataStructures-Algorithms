#include <stdio.h>
#include <string.h>
void print_all(const char *words[]);
const char *longest(const char *words[]);

int main()
{
    const char *words[] = {"hello", "world", "C", NULL};
    print_all(words);
    printf("------------------\n");
    const char *p = longest(words);
    printf("%s\n" , p);
    return 0;
}

void print_all(const char *words[])
{
    int i = 0;
    while (words[i] != NULL)
    {
        printf("%s\n" , words[i]);
        i++;
    }
}

const char *longest(const char *words[])
{
    int slen = strlen(words[0]);
    int index = 0;
    int i = 0;
    while (words[i] != NULL)
    {
        if (strlen(*(words + i)) > slen)
        {
            slen = strlen(*(words + i));
            index = i;
        }
        i++;
    }
    return (words[index]);
}