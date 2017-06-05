/*************************************************************************
	> File Name: features.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月29日 星期三 09时36分21秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
//**********************************************排序***********************************************************************************
void BubbleSort_up(driver_info *head)  
{  
    driver_info *f, *p, *x, *y;  
    f = NULL;  
    if(head -> next == NULL || head -> next -> next == NULL)  
    {  
        return;  
    }  
    while(f != head->next->next)  
    {  
        for(p = head; p -> next -> next != f; p = p -> next)  
        {  
            if(strcmp(p -> next -> name , p -> next -> next ->name) < 0)  
            {  
                x = p -> next;  
                y = p -> next -> next;  
                p -> next = y;  
                x -> next = y -> next;  
                y -> next = x;  
            }  
        }  
        f = p -> next;  
    }  
}  
void BubbleSort_down(driver_info *head)  
{  
    driver_info *f, *p, *x, *y;  
    f = NULL;  
    if(head -> next == NULL || head -> next -> next == NULL)  
    {  
        return;  
    }  
    while(f != head->next->next)  
    {  
        for(p = head; p -> next -> next != f; p = p -> next)  
        {  
            if(strcmp(p -> next -> name , p -> next -> next ->name) > 0)  
            {  
                x = p -> next;  
                y = p -> next -> next;  
                p -> next = y;  
                x -> next = y -> next;  
                y -> next = x;  
            }  
        }  
        f = p -> next;  
    }  
}  
//******************************************查找*********************************************************************************************
driver_info *search_driver_number_self( driver_info *phead,char user_in_number[MAX_BYTE])
{
    driver_info *ptemp = phead,*pre;
    pre = ptemp;
    ptemp = ptemp->next;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    while(ptemp != NULL )
    {
        if(!strcmp(ptemp->number,user_in_number))
       {
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
            fputs("\n",stdout);
            sleep(1);
            return pre;
        }
        pre = pre->next;
        ptemp = ptemp->next;
    }
    return NULL;
}
driver_info *search_advanced_number( driver_info *phead)
{
    driver_info *ptemp = phead,*pre;
    char user_in_number[MAX_BYTE];
    pre = ptemp;
    ptemp = ptemp->next;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t                      输入要查询的司机编号 :");
    my_fgets(user_in_number,MAX_BYTE);
    while(ptemp != NULL )
    {
        if(!strcmp(ptemp->number,user_in_number))
       {
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
            fputs("\n",stdout);
            sleep(1);
            return pre;
        }
        pre = pre->next;
        ptemp = ptemp->next;
    }
    return NULL;
}
int search_vague_car_color_type(driver_info *phead )
{
    int i = 0;
    driver_info *ptemp = phead;
    char user_in_car_color[MAX_BYTE],user_in_car_type[MAX_BYTE];
    ptemp = ptemp->next;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t输入要查询车型颜色 :");
    my_fgets(user_in_car_color,MAX_BYTE);
    printf("\t\t\t\t输入要查询汽车品牌:");
    my_fgets(user_in_car_type,MAX_BYTE);
    while(ptemp != NULL )
    {
        if(!strcmp(ptemp->car_color,user_in_car_color) || !strcmp(ptemp->car_type,user_in_car_type))
       {
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
            fputs("\n",stdout);
            i++;
        }
        ptemp = ptemp->next;
    }
    if(i)
    {printf("\n\n\t\t\t\t按任意键返回上一级菜单");getchar();return _SUCCEES;}
    else
    {printf("\n\n\t\t\t\t未找到所查找车辆,按任意键返回上一级菜单\n");getchar();return _FAIL;}
}
int  search_simple_car_number( driver_info *phead)
{
    driver_info *ptemp = phead;
    char user_in_car_number[MAX_BYTE];
    ptemp = ptemp->next;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t输入要查询车牌号 :");
    my_fgets(user_in_car_number,MAX_BYTE);
    while(ptemp != NULL )
    {
        if(!strcmp(ptemp->car_number,user_in_car_number))
       {
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
            fputs("\n",stdout);
           printf("\t\t\t\t按任意键返回上一级菜单\n");
            getchar();
        return _SUCCEES;
        }
        ptemp = ptemp->next;
    }
    printf("\n\n\t\t\t\t未找到所查找车辆,按任意键返回上一级菜单\n");
    getchar();
    return _FAIL;
}
int  search_simple_name( driver_info *phead)
{
    driver_info *ptemp = phead;
    ptemp = ptemp->next;
    char user_in_name[MAX_BYTE];
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t输入要查询司机姓名 :");
    my_fgets(user_in_name,MAX_BYTE);
    while(ptemp != NULL )
    {
        if(!strcmp(ptemp->name,user_in_name))
       {
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
            fputs("\n",stdout);
            getchar();
            return _SUCCEES;
        }
        ptemp = ptemp->next;
    }
    printf("未找到所查找司机\n");
    getchar();
    return _FAIL;
}
//******************************************打印****************************************************************
void single_print(driver_info* phead)
{
	driver_info *ptemp=phead;
	ptemp = ptemp->next;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
        fputs("\n",stdout);
}
void print(driver_info* phead)
{
	driver_info *ptemp=phead;
	ptemp = ptemp->next;
	while(ptemp!=NULL)
	{       
       printf("\t\t\t\t司机编号   司机姓名   性别  职位   注册日期    车型    车牌  汽车颜色      联系电话\n ");
       printf("\t\t\t\t%s  %s %s %s  %s  %s   %s  %s       %s",ptemp->number,ptemp->name,ptemp->sex,ptemp->postion,ptemp->date,ptemp->car_type,ptemp->car_number,ptemp->car_color,ptemp->phone_number);
        fputs("\n",stdout);
        ptemp = ptemp->next;
	}
}

//****************************************************删除**********************************************************
int delete_old_driver(driver_info *phead)
{
    char k;
    driver_info *pre,*pnext;
    if((pre = search_advanced_number(phead)) != NULL)
    {
        printf("\n\n\n\t\t\t\t确认删除此信息？(y/n)");
        k = getchar();
        getchar();
        if(k == 'y')
        {
        pnext = pre->next->next;
        pre->next = pnext;
        mem_to_file(phead);
        printf("\t\t\t删除成功！按任意键返回上一级菜单\n");
        getchar();
        return _SUCCEES;
        }
        else 
        {
            printf("\t\t\t已取消，按任意键返回上一级菜单\n");
            getchar();
            return _FAIL;
        }
    }
    else{printf("\t\t\t未找到要删除的信息，返回上一级菜单\n");sleep(3);
        return _FAIL;}
}
//****************************************************统计*********************************************************
int count(driver_info *phead)
{
    driver_info *ptemp = phead;
    int count;
    char user_in_sex[MAX_BYTE],user_in_car_type[MAX_BYTE],user_in_car_color[MAX_BYTE],k[10];
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t请输入您想要统计的信息\n\n");
    printf("\t\t\t\t1. 性别\n");
    printf("\t\t\t\t2. 车型\n");
    printf("\t\t\t\t3. 车型&颜色\n");
    printf("\t\t\t\t\t");
    fflush(stdin);
    my_fgets(k,10);
    switch(k[0])
    {
        case '1':
                printf("\t\t\t\t请输入您想要统计的性别:");
                fflush(NULL);
                my_fgets(user_in_sex,MAX_BYTE);
                count =  count_sex(user_in_sex,ptemp);
                printf("\t\t\t\t经统计，性别为%s的司机有%d人\n",user_in_sex,count);
                getchar();
                return _SUCCEES;
        case '2':
                printf("\t\t\t\t请输入您想要统计的车型:");
                fflush(NULL);
                my_fgets(user_in_car_type,MAX_BYTE);
                count = count_car_type(user_in_car_type,ptemp);
                printf("\t\t\t\t经统计，车型为%s的汽车有%d辆\n",user_in_car_type,count);
                getchar();
                return _SUCCEES;
        case '3':
                printf("\t\t\t\t请输入您想要统计的车型:");
                fflush(NULL);
                my_fgets(user_in_car_type,MAX_BYTE);
                printf("\t\t\t\t请输入您想要统计的颜色:");
                fflush(NULL);
                my_fgets(user_in_car_color,MAX_BYTE);
                count = count_car_type_color(user_in_car_type,user_in_car_color,ptemp);
                printf("\t\t\t\t经统计，车型为%s，颜色为%s的汽车有%d辆\n",user_in_car_type,user_in_car_color,count);
                getchar();
                return _SUCCEES;
        default :printf("error");sleep(3);return _FAIL;
    }
}
int count_car_type_color(char user_in_car_type[],char user_in_car_color[],driver_info *phead)
{
    int count = 0;
    driver_info *ptemp =phead->next;
    while(ptemp != NULL)
    {
        if(!strcmp(user_in_car_type,ptemp->car_type)&&!strcmp(user_in_car_color,ptemp->car_color))
        count++;
        ptemp = ptemp->next;
    }
    return count;
}
int count_car_type(char user_in_car_type[],driver_info *phead)
{
    int count = 0;
    driver_info *ptemp =phead->next;
    while(ptemp != NULL)
    {
        if(!strcmp(user_in_car_type,ptemp->car_type))
        count++;
        ptemp = ptemp->next;
    }
    return count;
}
int count_sex(char user_in_sex[],driver_info *phead)
{
    int count = 0;
    driver_info *ptemp =phead->next;
    while(ptemp != NULL)
    {
        if(!strcmp(user_in_sex,ptemp->sex))
        count++;
        ptemp = ptemp->next;
    }
    return count;
}
//**********************************************************修改******************************************************
int  change_driver_self(char user_in_number[])
{
    driver_info *ptemp,*phead,*pnew,*plook;
    int i =3;
    char k;
    phead = file_to_mem();
    ptemp = phead;
    if((pnew = search_driver_number_self(ptemp,user_in_number)) != NULL)
    {
        plook = pnew;
        pnew = pnew->next;
    while(i)
    {
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t请输入您想要修改的信息：\n");
    printf("\t\t\t\t1.编号     2.姓名   3.性别    4.职位     5.密码  \n"); 
    printf("\t\t\t\t6.注册日期 7.车型   8.车牌号  9.车辆颜色 0.手机号\n");
    printf("                               ");
        k =getchar();
    getchar();
        switch(k)
    {
        case '1':printf("\t\t\t\t请输入编号\n");printf("\t\t                ");my_fgets(pnew->number,MAX_BYTE );break;
        case '2':printf("\t\t\t\t请输入姓名\n");printf("\t\t                ");my_fgets(pnew->name,MAX_BYTE );break;
        case '3':printf("\t\t\t\t请输入性别（female/male）\n");printf("\t\t                ");my_fgets(pnew->sex,8 );break;
        case '4':printf("\t\t\t\t请输入职位\n");printf("\t\t                ");my_fgets(pnew->postion,MAX_BYTE );break;
        case '5':printf("\t\t\t\t请输入密码\n");printf("\t\t                ");my_fgets(pnew->secretcode,MAX_BYTE );secretcode_in(pnew->secretcode);break;
        case '6':printf("\t\t\t\t请输入注册日期\n");printf("\t\t                ");my_fgets(pnew->date,MAX_BYTE );break;
        case '7':printf("\t\t\t\t请输入车型\n");printf("\t\t                ");my_fgets(pnew->car_type,MAX_BYTE );break;
        case '8':printf("\t\t\t\t请输入车牌号\n");printf("\t\t               ");my_fgets(pnew->car_number,MAX_BYTE );break;
        case '9':printf("\t\t\t\t请输入车辆颜色\n");printf("\t\t                ");my_fgets(pnew->car_color,MAX_BYTE );break;
        case '0':printf("\t\t\t\t请输入手机号\n");printf("\t\t                ");my_fgets(pnew->phone_number,MAX_BYTE );break;
    }
    printf("\t\t\t\t\t信息如下\n");
    single_print(plook);
    printf("\t\t\t\t\t确认信息无误？（y/n）");
    k = getchar();
        getchar();
    setbuf(stdin,NULL);
        if(k == 'y')
     {
        mem_to_file(phead);
        return _SUCCEES;
     }
        else 
        {i--;
        continue;
        }
    }
    }
    else printf("\t\t司机编号不存在\n");
    sleep(1);
    return _FAIL;
}
int  change_old_driver(driver_info *phead)
{
    driver_info *ptemp = phead,*pnew,*plook;
    int i =3;
    char k;
    if((pnew = search_advanced_number(ptemp)) != NULL)
    {
        plook = pnew;
        pnew = pnew->next;
    while(i)
    {
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t请输入您想要修改的信息：\n");
    printf("\t\t\t\t1.编号     2.姓名   3.性别    4.职位     5.密码  \n"); 
    printf("\t\t\t\t6.注册日期 7.车型   8.车牌号  9.车辆颜色 0.手机号\n");
    k =getchar();
    getchar();
        switch(k)
    {
        case '1':printf("\t\t\t\t请输入编号\n");printf("\t\t             ");my_fgets(pnew->number,MAX_BYTE );break;
        case '2':printf("\t\t\t\t请输入姓名\n");printf("\t\t             ");my_fgets(pnew->name,MAX_BYTE );break;
        case '3':printf("\t\t\t\t请输入性别（female/male）\n");printf("\t\t             ");my_fgets(pnew->sex,8 );break;
        case '4':printf("\t\t\t\t请输入职位\n");printf("\t\t             ");my_fgets(pnew->postion,MAX_BYTE );break;
        case '5':printf("\t\t\t\t请输入密码\n");printf("\t\t             ");my_fgets(pnew->secretcode,MAX_BYTE );secretcode_in(pnew->secretcode);break;
        case '6':printf("\t\t\t\t请输入注册日期\n");printf("\t\t             ");my_fgets(pnew->date,MAX_BYTE );break;
        case '7':printf("\t\t\t\t请输入车型\n");printf("\t\t             ");my_fgets(pnew->car_type,MAX_BYTE );break;
        case '8':printf("\t\t\t\t请输入车牌号\n");printf("\t\t             ");my_fgets(pnew->car_number,MAX_BYTE );break;
        case '9':printf("\t\t\t\t请输入车辆颜色\n");printf("\t\t             ");my_fgets(pnew->car_color,MAX_BYTE );break;
        case '0':printf("\t\t\t\t请输入手机号\n");printf("\t\t             ");my_fgets(pnew->phone_number,MAX_BYTE );break;
    }
    printf("\t\t\t\t\t信息如下\n");
    single_print(plook);
    printf("\t\t\t\t\t确认信息无误？（y/n）");
    k = getchar();
        getchar();
    setbuf(stdin,NULL);
        if(k == 'y')
     {
        mem_to_file(phead);
        return _SUCCEES;
     }
        else 
        {i--;
        continue;
        }
    }
    }
    else printf("\t\t司机编号不存在\n");
    sleep(3);
    return _FAIL;
}
//**********************************************************新建*************************************************************
int create_new_driver(driver_info *phead)
{
    driver_info *ptemp = phead,*pnew;
    int i = 3;
    char k;
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    while(i)
    {
        system("clear");
    pnew = (driver_info *)malloc(sizeof(driver_info)) ;
    ptemp->next = pnew;
    pnew->next = NULL;
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t请输入编号: ");
    my_fgets(pnew->number,10 );
    printf("\t\t\t\t\t请输入姓名: ");
    my_fgets(pnew->name,MAX_BYTE );
    printf("\t\t\t\t\t请输入性别（female/male）: ");
    my_fgets(pnew->sex,8 );
    printf("\t\t\t\t\t请输入职位: ");
    my_fgets(pnew->postion,MAX_BYTE );
    printf("\t\t\t\t\t请输入密码: ");
    system("stty -echo ");
    my_fgets(pnew->secretcode,MAX_BYTE );
    secretcode_in(pnew->secretcode);
    system("stty echo");
    printf("\n\t\t\t\t\t请输入注册日期: ");
    my_fgets(pnew->date,MAX_BYTE );
    printf("\t\t\t\t\t请输入车型: ");
    my_fgets(pnew->car_type,MAX_BYTE );
    printf("\t\t\t\t\t请输入车牌号: ");
    my_fgets(pnew->car_number,MAX_BYTE );
    printf("\t\t\t\t\t请输入车辆颜色: ");
    my_fgets(pnew->car_color,MAX_BYTE );
    printf("\t\t\t\t\t请输入手机号: ");
    my_fgets(pnew->phone_number,MAX_BYTE );
    printf("\t\t\t\t\t信息如下\n");
    single_print(ptemp);
    printf("\t\t\t\t\t确认信息无误？（y/n）");
    k = getchar();
    getchar();
        setbuf(stdin,NULL);
        if(k  == 'y')
    {
        mem_to_file(phead);
        return _SUCCEES;
    }
        else {
            ptemp->next = NULL;
            free(pnew);
            i--;
            continue;
        }
    }
    return _FAIL;
}
driver_info *entry_driver_information()
{
    char tem[MAX_BYTE],flag[]="end ";
    driver_info *phead,*pnew,*pend;
	pnew = (driver_info *)malloc(sizeof(driver_info));
	pend = phead = pnew;
	pnew->next = NULL;
	do
	{
         printf("\t\t\t\t请输入编号\n");
        printf("\t\t\t\t");
        my_fgets(tem,MAX_BYTE );
         if(!strcmp(tem,flag))
        break;
    	pnew = (driver_info *)malloc(sizeof(driver_info));
		pend->next = pnew;
		pend = pnew;
		pnew->next = NULL;
        strcpy(pnew->number,tem);
        printf("\t\t\t\t请输入姓名\n");
        printf("\t\t\t\t");
        my_fgets(pnew->name,MAX_BYTE );
         printf("\t\t\t\t请输入性别（female/male）\n");
        printf("\t\t\t\t");
        my_fgets(pnew->sex,8 );
         printf("\t\t\t\t请输入职位\n");
        printf("\t\t\t\t");
        my_fgets(pnew->postion,MAX_BYTE );
         printf("\t\t\t\t请输入密码\n");
        printf("\t\t\t\t");
        system("stty -echo");
        my_fgets(pnew->secretcode,MAX_BYTE );
        secretcode_in(pnew->secretcode);
        system("stty echo");
         printf("\t\t\t\t请输入注册日期\n");
        printf("\t\t\t\t");
        my_fgets(pnew->date,MAX_BYTE );
         printf("\t\t\t\t请输入车型\n");
        printf("\t\t\t\t");
        my_fgets(pnew->car_type,MAX_BYTE );
         printf("\t\t\t\t请输入车牌号\n");
        printf("\t\t\t\t");
        my_fgets(pnew->car_number,MAX_BYTE );
         printf("\t\t\t\t请输入车辆颜色\n");
        printf("\t\t\t\t");
        my_fgets(pnew->car_color,MAX_BYTE );
         printf("\t\t\t\t请输入手机号\n");
        printf("\t\t\t\t");
        my_fgets(pnew->phone_number,MAX_BYTE );
    }
	while(1);
	return phead;
}
//**********************************************************文件读写**********************************************************    
driver_info *file_to_mem(void)
{
    FILE *fp,*test;
    driver_info *pnew,*phead,*pend,*pre,*ptemp;
	pnew = (driver_info *)malloc(sizeof(driver_info));
	pend = phead = pnew;
	pnew->next = NULL;
    if((fp = fopen("driver_information","r")) != NULL)
    {
    while(feof(fp) == 0)
    {
        pnew = (driver_info *)malloc(sizeof(driver_info));
		pend->next = pnew;
		pend = pnew;
		pnew->next = NULL;
        my_fscanf(fp,pnew->number);
        my_fscanf(fp,pnew->name);
        my_fscanf(fp,pnew->sex);
        my_fscanf(fp,pnew->postion);
        my_fscanf(fp,pnew->secretcode);
        my_fscanf(fp,pnew->date);
        my_fscanf(fp,pnew->car_type);
        my_fscanf(fp,pnew->car_number);
        my_fscanf(fp,pnew->car_color);
        my_fscanf(fp,pnew->phone_number);
    }
    fclose(fp);
    ptemp =phead->next;
    pre =phead;
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
        pre =pre->next;
    }
    pre->next =NULL;

    return phead;
    }
    else printf("\n\n\t\t\t\t信息文件不存在,请新建信息，在编号处输入end加回车终止\n");
    phead = entry_driver_information();
    mem_to_file(phead);
    exit(1);
    
}
void mem_to_file(driver_info* phead)
{
    FILE *fp;
    fp = fopen("driver_information","w+");
	driver_info *ptemp=phead;
	ptemp = ptemp->next;
	while(ptemp!=NULL)
	{
        fputs(ptemp->number,fp);
        fputs(ptemp->name,fp);
        fputs(ptemp->sex,fp);
        fputs(ptemp->postion,fp);
        fputs(ptemp->secretcode,fp);
        fputs(ptemp->date,fp);
        fputs(ptemp->car_type,fp);
        fputs(ptemp->car_number,fp);
        fputs(ptemp->car_color,fp);
        fputs(ptemp->phone_number,fp);
        ptemp = ptemp->next;
    }
    fclose(fp);
    }
