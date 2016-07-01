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
    char phone_number[13];            //手机号
    struct informations_driver *next;//
}driver_info;

int  choose_manager_features();
int choose_sort(driver_info *phead);
int  choose_in_up();
int choose_user_up(void); 
int choose_user_in(void) ;
void welcome(void);
int sign_up_manager();
int sign_up_driver();
int sign_in_manager();
int sign_in_manager_compare_secretcode(long postion,char user_in_secretcode[]);
long sign_in_manager_compare_number(char user_in_number[]);
int sign_in_driver();
int sign_in_driver_compare_secretcode(long postion,char user_in_secretcode[]);
long sign_in_driver_compare_number(char user_in_number[]);
void secretcode_out(char secretcode[]);
void secretcode_in(char secretcode[]);
void my_fscanf(FILE *fp,char array[]);
void my_fgets(char array[],int len);
void mem_to_file(driver_info* phead);
driver_info *file_to_mem(void);
driver_info *entry_driver_information();
int create_new_driver(driver_info *phead);
int  change_old_driver(driver_info *phead);
int count_sex(char user_in_sex[],driver_info *phead);
int count_car_type(char user_in_car_type[],driver_info *phead);
int count_car_type_color(char user_in_car_type[],char user_in_car_color[],driver_info *phead);
int count(driver_info *phead);
int delete_old_driver(driver_info *phead);
void print(driver_info* phead);
void single_print(driver_info* phead);
int  search_simple_name( driver_info *phead);
int  search_simple_car_number( driver_info *phead);
int search_vague_car_color_type(driver_info *phead );
driver_info *search_advanced_number( driver_info *phead);
void BubbleSort_down(driver_info *head);
void BubbleSort_up(driver_info *head);  
#endif
