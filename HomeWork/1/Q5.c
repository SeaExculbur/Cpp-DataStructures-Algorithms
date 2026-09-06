#include <stdio.h>
const char *pick(const char *opts[], int n, int index);

int main()
{
    const char *opts[] = {"Hello" , "World" , "Hi"};
    int n = 3;
    int index = 0;
    printf("请输入下标\n");
    scanf("%d" , &index);
     typedef const char *(*picker_t)(const char *[], int, int);
     picker_t f = &pick;
     const char *result = f(opts , n , index);
     printf("%s" , result);
    return 0;

}

const char *pick(const char *opts[], int n, int index)
{
    const char *p = "invalid";
    const char *res = "-1";
    if (opts[0] == NULL)
    {
        return res;
    }
    if (index >= n || index < 0)
    {
        return p;
    }
    return (opts[index]);
}