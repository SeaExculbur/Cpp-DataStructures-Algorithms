#include <stdio.h>
#include <stdlib.h>
int *safe_alloc(size_t bytes);

int main()
{
    size_t bts;
    printf("请输入申请的字节数（非负数）\n");
    if (scanf("%zu" , &bts) != 1)
    {
        printf("输入无效\n");
        return 1;
    }
    int *ptr = safe_alloc(bts);
    if (ptr == NULL)
    {
        printf("该bts非法\n");
        return 1;
    }
    free(ptr);
    return 0;
}

int *safe_alloc(size_t bytes)
{
    if (bytes == 0)
    {
        return NULL;
    }
    int *p = malloc(bytes);
    return p;
}