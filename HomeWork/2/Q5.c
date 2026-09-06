#include <stdio.h>
#include <stdlib.h>
int *make(int count) {
    int *p = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        {
            p[i] = i;
        }
    return p;
}

void use() {
    int *a = make(5);
    printf("%d\n", a[0]);
    free(a);
}

int main()
{
    void (*p)();
    p = use;
    p();
    return 0;
}