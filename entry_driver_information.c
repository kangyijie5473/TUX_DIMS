/*************************************************************************
	> File Name: entry_driver_information.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月22日 星期三 11时44分55秒
 ************************************************************************/
#include<string.h>
#include"informations_driver.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_BYTE 22
/*
driver_info *find_end(driver_info *phead)
{
    driver_info *ptemp = phead;
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    return ptemp;
}
void swap(int *a,int *b)
{
    int temp;
    temp =*a;
    *a = *b;
    *b = temp;
}
driver_info* GetPartion(driver_info* pBegin,driver_info* pEnd)  
{  
    int age = pBegin->age;  
    driver_info* p = pBegin;  
    driver_info* q = p->next;  
    while(q != pEnd)  
    {  
        if(q->age < age)  
        {  
            p = p->next;  
            swap(&p->age,&q->age);  
        }  
  
        q = q->next;  
    }  
    swap(&p->age,&pBegin->age);  
    return p;  
}  
  
void QuickSort(driver_info* pBeign, driver_info* pEnd)  
{  
    if(pBeign != pEnd)  
    {  
        driver_info* partion = GetPartion(pBeign,pEnd);  
        QuickSort(pBeign,partion);  
        QuickSort(partion->next,pEnd);  
    }  
}  

int main(void)
{
    driver_info *phead,*pend;
    phead = create();
    pend = find_end(phead);
    QuickSort(phead->next,pend);
    print(phead);
}
*/            
void print(driver_info* phead)
{
	driver_info *ptemp=phead;
	ptemp = ptemp->next;
	while(ptemp!=NULL)
	{
        fputs(ptemp->number,stdout);
        fputs(ptemp->name,stdout);
        fputs(ptemp->sex,stdout);
        fputs(ptemp->secretcode,stdout);
        fputs(ptemp->date,stdout);
        fputs(ptemp->car_type,stdout);
        fputs(ptemp->car_number,stdout);
        fputs(ptemp->car_color,stdout);
        fputs(ptemp->phone_number,stdout);

		ptemp = ptemp->next;
	}
}
driver_info *entry_driver_information()
{
    char tem[MAX_BYTE],flag[]="end\n";
    driver_info *phead,*pnew,*pend;
	pnew = (driver_info *)malloc(sizeof(driver_info));
	pend = phead = pnew;
	pnew->next = NULL;
	do
	{

         printf("请输入编号\n");
        fgets(tem,MAX_BYTE,stdin);
        if(!strcmp(tem,flag))
        break;
    	pnew = (driver_info *)malloc(sizeof(driver_info));
		pend->next = pnew;
		pend = pnew;
		pnew->next = NULL;
        strcpy(pnew->number,tem);
        printf("请输入姓名\n");
        fgets(pnew->name,MAX_BYTE,stdin);
         printf("请输入性别（female/male）\n");
        fgets(pnew->sex,8,stdin);
         printf("请输入职位\n");
        fgets(pnew->postion,MAX_BYTE,stdin);
         printf("请输入密码\n");
        fgets(pnew->secretcode,MAX_BYTE,stdin);
         printf("请输入注册日期\n");
        fgets(pnew->date,MAX_BYTE,stdin);
         printf("请输入车型\n");
        fgets(pnew->car_type,MAX_BYTE,stdin);
         printf("请输入车牌号\n");
        fgets(pnew->car_number,MAX_BYTE,stdin);
         printf("请输入车辆颜色\n");
        fgets(pnew->car_color,MAX_BYTE,stdin);
         printf("请输入手机号\n");
        fgets(pnew->phone_number,MAX_BYTE,stdin);
    }
	while(1);
	return phead;
}
void mem_to_file(driver_info* phead)
{
    FILE *fp;
    fp = fopen("driver_infomation","a+");
	driver_info *ptemp=phead;
	ptemp = ptemp->next;
	while(ptemp!=NULL)
	{
       fprintf(fp,"%s",ptemp->number);
        // fputs(ptemp->number,fp);
        fputs(ptemp->name,fp);
        fputs(ptemp->sex,fp);
        fputs(ptemp->secretcode,fp);
        fputs(ptemp->date,fp);
        fputs(ptemp->car_type,fp);
        fputs(ptemp->car_number,fp);
        fputs(ptemp->car_color,fp);
        fputs(ptemp->phone_number,fp);
		ptemp = ptemp->next;
    }
}

int main(void)
{
    driver_info *head;
    head = entry_driver_information();
    print(head);
    mem_to_file(head);
}
