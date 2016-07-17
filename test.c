/*************************************************************************
	> File Name: test.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月29日 星期三 09时28分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"informations_driver.h"
#include"informations_manager.h"
#include"my_fun.c"
#include"features.c"
#include"sign.c"
#include"ui.c"

int main(void)
{
    int i;
    system("clear");
    welcome();
    system("sl -alFe");
    system("clear");
    i = choose_in_up();
}
