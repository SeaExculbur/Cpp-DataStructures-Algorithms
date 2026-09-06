#include <stdio.h>
void apply(int arr[], int n, int (*op)(int));
int neg(int x);
int square(int x);

int main()
{
    int arr[] = {1 ,2 ,3 ,4 ,5 ,6};
    apply(arr , 6 , neg);
    for (int i = 0 ; i < 6 ; i++)
    {
        printf("%d\n" , arr[i]);
    }
    return 0;
}

void apply(int arr[], int n, int (*op)(int))
{
    for (int i = 0 ; i < n ; i++)
    {
        arr[i] = op(arr[i]);
    }
}

int square(int x)
{
    int temp = x;
    if (x == 0)
    {
        return 0;
    }
    else if (x > 0)
    {
        for (int i = 1 ; i < temp ; i++)
        {
            x = x*temp;
        }
        return x;
    }
    else
    {
        for (int i = 1 ; i > temp ; i--)
        {
            x = x*temp;
        }
        return (1 / x);
    }

}

int neg(int x)
{
    if (x > 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}