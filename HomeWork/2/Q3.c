#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *dup_prefix(const char *s, int k);

int main()
{
    const char *p = "HelloWorld";
    int k;
    printf("%s\n" , p);
    printf("请输入你要截断多少个字符\n");
    if (scanf("%d" , &k) != 1)
    {
        return 1;
    }
    char *ptr = dup_prefix(p , k);
    if (ptr == NULL)
    {
        printf("打印失败\n");
        return 1;
    }
    printf("%s\n" , ptr);
    free(ptr);
    return 0;
}

char *dup_prefix(const char *s, int k)
{
    if (s == NULL || k < 0)
    {
        return NULL;
    }
    int len = strlen(s);
    if (k >= len)
    {
        char *str = malloc(len + 1);
        strcpy(str, s);
        return str;
    }
    char *ptr = malloc(k + 1);
    for (int i = 0 ; i < k ; i++)
    {
        ptr[i] = s[i];
    }
    ptr[k] = '\0';
    return ptr;
}