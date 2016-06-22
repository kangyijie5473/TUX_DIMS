/*************************************************************************
	> File Name: choose_in_up.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 20时23分18秒
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
int choose_in_up()
{
    char choice[2];
    printf("请输入您的选择\n");
    printf("1.登陆\n");
    printf("2.注册\n");
    printf("0.退出程序\n");
    fgets(choice,2,stdin);
    switch(choice[0])
    {
        case '1': return 1;
        case '2': return 2;
        case '0': exit(0);
    }
}
