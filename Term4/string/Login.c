#include <stdio.h>
#include <string.h>
void login(char correct_name[10] , char correct_password[10]);
int main()
{
    char correct_name[10] = "小明";
    char correct_password[10] = "123456";
    login(correct_name, correct_password);
}

void login(char correct_name[10] , char correct_password[10])
{
    int count = 0;
    while (count < 3)
    {
        char name[10];
        char password[10];
        printf("请输入你的用户名\n");
        scanf("%s" , name);
        printf("请输入你的密码\n");
        scanf("%s" , password);
        if (!strcmp(correct_name,name) && !strcmp(correct_password,password))
        {
            printf("login success!");
            break;
        }
        else
        {
            printf("用户名或密码错误，请重新输入");
        }
        count++;
        if (count == 3)
        {
            printf("用户：%s已冻结！" , name);
        }
    }
}