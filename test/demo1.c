#include <stdio.h>
void count(char arr[][10]);
int main()
{
    char arr[][10] = 
    {
        "Hello",
        "World",
        "XM"
    };
    count(arr);

    return 0;
}

void count(char arr[][10])
{
    printf("%d" , sizeof(*arr));

}