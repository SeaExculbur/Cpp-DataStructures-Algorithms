#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// 选举投票
int random_num();
struct spot
{
    char name[100];
    int count;
};

int main()
{
    srand(time(NULL));
    char spot_name[100];
    struct spot arr[4] = {{"A" , 0},{"B" , 0},{"C" , 0},{"D" , 0}};
    for (int j = 1; j <= 80 ; j++)
    {
        int num = random_num();
        arr[num].count++;
    }
    int max = arr[0].count;
    strcpy(spot_name , arr[0].name);
    for (int i = 1 ; i < 4 ; i++)
    {
        struct spot temp = arr[i];
        if (temp.count > max)
        {
            max = temp.count;
            strcpy(spot_name ,temp.name);
        }
    }
    printf("选中%s , 有%d票\n" , spot_name , max);
    return 0;

}
int random_num()
{
    int num = rand();
    return (num % 4);
}
