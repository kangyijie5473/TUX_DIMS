/*************************************************************************
	> File Name: choose.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 19时33分36秒
 ************************************************************************/

#include<stdio.h>
int choose_user(void) //bug 输入非法时 提示信息会多出现一次
{
    int key;
    char choice[2];
    while(1)
    {
    printf("您的身份是？请输入对应序号（以输入的第一位为准，多输入无效）\n");
    printf("1.管理员\n");
    printf("2.司机\n");
    printf("0.返回上一级\n");
    fflush(stdin);
    fgets(choice,2,stdin);
    fflush(stdin);
        switch(choice[0])
    {
        case '1':key = sign_in_manager();if(key) 
        case '2':sign_in_driver();
        case '0':return -1;
        default :printf("输入非法\n");
    }
      fflush(stdin);
    }
}
