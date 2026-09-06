#include <stdio.h>
void print(char str[]);
void print2(char *p);

int main()
{
    char str[] = "hello";
    char *p =  "hello";
    str[0] = 'a';
    printf("%s\n" , str);
    printf("%s\n" , p);

    printf("-------------------\n");
    print(str);
    print2(p);
    return 0;
}

void print(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c" , str[i]);
        i++;
    }
    printf("\n--------------\n");
}

void print2(char *p)
{
    while (*p != '\0')
    {
       printf("%c" , *p);
       p++;
    }
    printf("\n");
}