#include <stdio.h>
void swap(int *a, int *b);
int main()
{
    int x = 10;
    int y = 20;
    int *a = &x;
    int *b = &y;
    swap(a , b);
    printf("%d , %d" , x , y);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}