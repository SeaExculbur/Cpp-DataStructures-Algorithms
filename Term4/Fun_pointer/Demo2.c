#include <stdio.h>
void print_matrix(int (*p)[4], int rows);

int main()
{
    int b[2][4] = 
    {
    {1,2,3,4},
    {5,6,7,8}
    };

    int (*p)[4] = b;
    print_matrix(p ,2);
    return 0;
}

void print_matrix(int (*p)[4], int rows)
{
    if (p == NULL || rows <= 0)
    {
        return;
    }
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            printf("%d" , *(*(p+i)+j));
        }
        printf("\n");
    }
}