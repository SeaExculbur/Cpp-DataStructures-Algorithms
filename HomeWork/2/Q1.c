#include <stdio.h>
#include <stdlib.h>
int *alloc_int_array(int n);

int main()
{
    int n;
    printf("请输入要申请几个int长度的内存\n");
    if (scanf("%d" , &n) != 1)
    {
        printf("输入无效\n");
        return 1;
    }
    int *p = alloc_int_array(n);   // 函数返回一个指针
    if (p == NULL)
    {
        printf("该n值无效\n");
        return 1;
    }
    for (int i = 0 ; i < n ; i++)
    {
        *(p+i) = i+1;
        printf("%d\n" , *(p+i));
    }
    free(p);       // 记得释放堆里的内存
    return 0;
}

int *alloc_int_array(int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    // 不能直接写malloc(n)的原因是 malloc函数里传入的参数是申请的字节数，如果只写n，那就是申请n个字节，而不是n个int所需要的字节
    int *p = malloc(n * sizeof(int));
    return p;
}