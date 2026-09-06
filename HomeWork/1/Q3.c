#include <stdio.h>
void add_row(int (*row)[3], int ncols);

int main()
{
    int m[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3] = m;
    printf("%d , %d , %d\n" , (*p)[0] , (*p)[2] , (*(p+1))[1]);
    add_row(p , 3);
    add_row(p+1 , 3);
    for (int i = 0 ; i < 2 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            printf("%d\n" , *(*(p+i)+j));
        }
    }   
    return 0;
}

void add_row(int (*row)[3], int ncols)
{
    for (int i = 0 ; i < ncols ; i++)
    {
        (*row)[i] = (*row)[i] + 10; 
    }

}