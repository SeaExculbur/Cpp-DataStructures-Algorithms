#include <stdio.h>
int main()
{
    FILE *p = fopen("E:\\Clanguage\\Term4\\File\\test.txt" , "r");
    int c;
    while ((c = fgetc(p)) != -1)
    {
        printf("%c" , c);
    }
    return 0;
}