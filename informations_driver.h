/*************************************************************************
	> File Name: informations_driver.h
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 17时41分46秒
 ************************************************************************/

#ifndef _INFORMATIONS_DRIVER_H
#define _INFORMATIONS_DRIVER_H
#define MAX_BYTE 22
#define _SUCCEES 1
#define _FAIL   0

typedef struct informations_driver
{
    char number[10];                   //8位编号
    char name[MAX_BYTE];               //名字 
    char sex[8];                      //性别male或者female
    char postion[MAX_BYTE];           //职位
    char secretcode[MAX_BYTE];        //密码
    char date[MAX_BYTE];              //日期
    char car_type[MAX_BYTE];          //车型
    char car_number[MAX_BYTE];        //车牌
    char car_color[MAX_BYTE];         //汽车颜色
    char phone_number[11];            //手机号
    struct informations_driver *next;//
}driver_info;
#endif
