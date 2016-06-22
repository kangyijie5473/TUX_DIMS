/*************************************************************************
.> File Name: sign_up_driver.c
.> Author: Kangyijie 
.> Mail:Kangyijie5473@gmail.com 
.> Created Time: 2016年06月17日 星期五 19时39分44秒
.************************************************************************/
#include<stdlib.h>
//#include"informations_driver.h"
#include<stdio.h>
#define MAX_BYTE 22
#define _SUCCEES 1
#define _FAIL   0

typedef struct informations_driver
{
    char driver_number[10];                   //8位编号
    char name[MAX_BYTE];               //名字 
    char sex[8];                      //性别male或者female
    char postion[MAX_BYTE];           //职位
    char secretcode[MAX_BYTE];        //密码
    char date[MAX_BYTE];              //日期
    char car_type[MAX_BYTE];          //车型
    char car_number[MAX_BYTE];        //车牌
    char car_color[MAX_BYTE];         //汽车颜色
    char phone_number[10];            //手机号
    struct informations_driver *pnext;//
}driver_info;
/*int sign_up_driver(FILE *fp_driver_information,driver_info *tem)
{
   tem = (driver_info *)malloc(sizeof(driver_info)); 
   if((fp_driver_information = fopen("driver_information","a+")) != NULL)
     {
         fseek(fp_driver_information,0,SEEK_END);
         printf("请输入8位编号\n");
         fgets(tem->number,10,stdin);
         fflush(stdin);
         fputs(tem->number,fp_driver_information);
         printf("请输入姓名\n");
         fgets(tem->name,MAX_BYTE,stdin);
         fputs(tem->name,fp_driver_information);
         printf("请输入性别（female/male）\n");
         fgets(tem->sex,8,stdin);
         fputs(tem->sex,fp_driver_information);
         printf("请输入职位\n");
         fgets(tem->postion,MAX_BYTE,stdin);
         fputs(tem->postion,fp_driver_information);
         printf("请输入密码\n");
         fgets(tem->secretcode,MAX_BYTE,stdin);
         //tem->secretcode = secretcode_in(tem->secretcode);   //密码未加密处理 输入未清空
         printf("请输入注册日期\n");
         fgets(tem->date,MAX_BYTE,stdin);
         fputs(tem->date,fp_driver_information);
         printf("请输入车型\n");
         fgets(tem->car_type,MAX_BYTE,stdin);
         fputs(tem->car_type,fp_driver_information);
         printf("请输入车牌号\n");
         fgets(tem->car_number,MAX_BYTE,stdin);
         fputs(tem->car_number,fp_driver_information);
         printf("请输入车辆颜色\n");
         fgets(tem->car_color,MAX_BYTE,stdin);
         fputs(tem->car_color,fp_driver_information);
         printf("请输入手机号\n");
         fgets(tem->phone_number,MAX_BYTE,stdin);
         fputs(tem->phone_number,fp_driver_information);
         return _SUCCEES;
       
}
   
   else printf("信息文件出现错误\n");
       return _FAIL;
}*/

int sign_up_driver(FILE *fp_driver_information)
{
   driver_info tem;
   if((fp_driver_information = fopen("driver_information","a+")) != NULL)
     {
         printf("请输入8位编号\n");
         fgets(tem.driver_number,10,stdin);
         
         fputs(tem.driver_number,fp_driver_information);
         printf("请输入姓名\n");
         fgets(tem.name,MAX_BYTE,stdin);
         fputs(tem.name,fp_driver_information);
         printf("请输入性别（female/male）\n");
         fgets(tem.sex,8,stdin);
         fputs(tem.sex,fp_driver_information);
         printf("请输入职位\n");
         fgets(tem.postion,MAX_BYTE,stdin);
         fputs(tem.postion,fp_driver_information);
         /*printf("请输入密码\n");
         fgets(tem.secretcode,MAX_BYTE,stdin);
         //tem->secretcode = secretcode_in(tem->secretcode);   //密码未加密处理 输入未清空
         printf("请输入注册日期\n");
         fgets(tem.date,MAX_BYTE,stdin);
         fputs(tem.date,fp_driver_information);
         printf("请输入车型\n");
         fgets(tem.car_type,MAX_BYTE,stdin);
         fputs(tem.car_type,fp_driver_information);
         printf("请输入车牌号\n");
         fgets(tem.car_number,MAX_BYTE,stdin);
         fputs(tem.car_number,fp_driver_information);
         printf("请输入车辆颜色\n");
         fgets(tem.car_color,MAX_BYTE,stdin);
         fputs(tem.car_color,fp_driver_information);
         printf("请输入手机号\n");
         fgets(tem.phone_number,MAX_BYTE,stdin);
         fputs(tem.phone_number,fp_driver_information);*/
         return _SUCCEES;
       
}
   
   else printf("信息文件出现错误\n");
       return _FAIL;
}
int main(void)
{
   FILE *fp;
   sign_up_driver(fp);
}
