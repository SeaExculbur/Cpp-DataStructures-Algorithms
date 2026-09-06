#include <stdio.h>
void row_sums(const int (*p)[4], int rows, int *out);

int main()
{
    int arr[3][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int out[3];
    const int (*p)[4] = arr;
    row_sums(p ,3 ,out);
    for (int i = 0 ; i < 3 ; i++)
    printf("%d\n" , out[i]);
    return 0;
}

void row_sums(const int (*p)[4], int rows, int *out)
{
    if (p == NULL || rows <= 0 || out == NULL)
    {
        return;
    }
    for (int i = 0 ; i < rows ; i++)
    {
        int temp = 0;
        for (int j = 0 ; j < 4 ; j++)
        {
            temp += *(*(p+i)+j);
        }
        *(out+i) = temp;
    }
}