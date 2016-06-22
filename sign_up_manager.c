/*************************************************************************
	> File Name: sign_up_manager.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月19日 星期日 10时41分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"informations_manager.h"
#define _SUCCEES 1
#define _FAIL 0
int sign_up_manager(FILE *fp_manager_information)
{
    manager_info tem;
    if((fp_manager_information = fopen("manager_information","a+")) != NULL)
    {
         printf("请输入8位编号\n");
         fgets(tem.manager_number,10,stdin);
         fflush(stdin);
         fputs(tem.manager_number,fp_manager_information);
         printf("请输入姓名\n");
         fgets(tem.name,MAX_BYTE,stdin);
         fputs(tem.name,fp_manager_information);
         printf("请输入性别（female/male）\n");
         fgets(tem.sex,8,stdin);
         fputs(tem.sex,fp_manager_information);
         printf("请输入职位\n");
         fgets(tem.postion,MAX_BYTE,stdin);
         fputs(tem.postion,fp_manager_information);
         printf("请输入密码\n");
         fgets(tem.secretcode,MAX_BYTE,stdin);
         fputs(tem.secretcode,fp_manager_information);
         //tem->secretcode = secretcode_in(tem->secretcode);   //密码未加密处理 输入未清空
         printf("请输入注册日期\n");
         fgets(tem.date,MAX_BYTE,stdin);
         fputs(tem.date,fp_manager_information);
        return _SUCCEES;
    }
    else printf("信息文件出现错误\n");
    return _FAIL;
}
int main(void)
{
    FILE *fp;
    sign_up_manager(fp);
}
