long sign_in_driver_compare_number(char user_in_number[])
{
   long postion;
   FILE *fp; 
   driver_info tem;
    if((fp = fopen("driver_information","r") ) != NULL)
    {
       while(feof(fp) == 0)
       {
       my_fscanf(fp, tem.number);
       my_fscanf(fp, tem.name);
       my_fscanf(fp, tem.sex);
       my_fscanf(fp, tem.postion);
       postion = ftell(fp);
       my_fscanf(fp, tem.secretcode);
       my_fscanf(fp, tem.date);
       my_fscanf(fp, tem.car_type);
       my_fscanf(fp, tem.car_number);
       my_fscanf(fp, tem.car_color);
       my_fscanf(fp, tem.phone_number);
        if(!strcmp(tem.number,user_in_number))
        {
            fclose(fp);
            return postion;
        }
        else 
        {
            continue;
        }
       }
      fclose(fp);
      return _FAIL;
   }
   else printf("\t\terror");
}
int sign_in_driver_compare_secretcode(long postion,char user_in_secretcode[])
{
    FILE *fp;
    char secretcode[MAX_BYTE];
    if((fp = fopen("driver_information","r")) != NULL)
    {
        fseek(fp,postion,SEEK_SET);
        my_fscanf(fp, secretcode);
        secretcode_out(secretcode);
        if(!strcmp(secretcode,user_in_secretcode))
        {
            fclose(fp);  
            return _SUCCEES;
        }
        else 
        {
            fclose(fp);
            return _FAIL;
        }
    }
    else printf("\n\t\tinformations file is error\n");
}
char* sign_in_driver(char user_in_number[MAX_BYTE])
{
    int i = 3;
    long int postion;
    char user_in_secretcode[MAX_BYTE];
    while(i)
    {
    system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                                     司机用户编码:");
    my_fgets(user_in_number,MAX_BYTE );
    printf("\t\t                                     司机用户密码:");
    system("stty -echo");
    my_fgets(user_in_secretcode,MAX_BYTE );
    system("stty echo");
    if(postion = sign_in_driver_compare_number(user_in_number) )
    {
        if(sign_in_driver_compare_secretcode(postion,user_in_secretcode))
            return user_in_number;
        else 
        {
            printf("\n\n\n\t\t                                     密码错误\n");
            sleep(1);
            i--;
            continue;
        }
    }
    else
    {
        printf("\n\n\n\t\t                                     司机用户编码不存在哦\n");
        sleep(1);
        i--;
    }
    }
    printf("\n\n\n\t\t                                     错误次数太多了噢\n ");
    sleep(1);
    return NULL;
   
}
long sign_in_manager_compare_number(char user_in_number[])
{
   long postion;
   FILE *fp; 
   manager_info tem;
    if((fp = fopen("manager_information","r") ) != NULL)
   {
       while(feof(fp) == 0)
       {
       my_fscanf(fp, tem.manager_number);
       my_fscanf(fp, tem.name);
       my_fscanf(fp, tem.sex);
       my_fscanf(fp, tem.postion);
       postion = ftell(fp);
       my_fscanf(fp, tem.secretcode);
       secretcode_out(tem.secretcode);
       my_fscanf(fp, tem.date);
        if(!strcmp(tem.manager_number,user_in_number))
           {
               fclose(fp);
               return postion;
           }
        else continue;
       }
       fclose(fp);
       return _FAIL;
   }
   else printf("\t\terror");
}
int sign_in_manager_compare_secretcode(long postion,char user_in_secretcode[])
{
    FILE *fp;
    char secretcode[MAX_BYTE];
    if((fp = fopen("manager_information","r")) != NULL)
    {
        fseek(fp,postion,SEEK_SET);
        my_fscanf(fp, secretcode);
        secretcode_out(secretcode);
        if(!strcmp(secretcode,user_in_secretcode))
            {
                fclose(fp);
                return _SUCCEES;
            }
        else 
        {
            fclose(fp);
            return _FAIL;
        }
    }
    else printf("\t\t                                信息文件出现错误\n");
}
int sign_in_manager()
{
    int i = 3;
    long int postion;
    char user_in_number[MAX_BYTE],user_in_secretcode[MAX_BYTE];
    while(i)
    {
    system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                             管理员用户编码:");
    my_fgets(user_in_number,MAX_BYTE );
    printf("\t\t                             管理员用户密码:");
    system("stty -echo");
    my_fgets(user_in_secretcode,MAX_BYTE );
    system("stty echo");
    if(postion = sign_in_manager_compare_number(user_in_number) )
    {
        if(sign_in_manager_compare_secretcode(postion,user_in_secretcode))
            return _SUCCEES;
        else 
        {
            printf("\n\n\n\t\t                             密码错误\n");
            sleep(1);
            i--;
            continue;
        }
    }
    else
    {
        printf("\n\n\n\t\t                             用户编码不存在\n");
        sleep(1);
        i--;
    }
    }
    printf("\n\n\n\t\t                             错误次数太多了噢\n ");
    sleep(1);
    return _FAIL;
   
}
int sign_up_driver()
{
   driver_info tem;
FILE *fp_driver_information;
   if((fp_driver_information = fopen("driver_information","a+")) != NULL)
     {
         printf("\n\n\t\t\t\t请输入8位编号:");
         my_fgets(tem.number,10 );
         fputs(tem.number,fp_driver_information);
         printf("\t\t\t\t请输入姓名:");
         my_fgets(tem.name,MAX_BYTE);
         fputs(tem.name,fp_driver_information);
         printf("\t\t\t\t请输入性别（female/male）:");
         my_fgets(tem.sex,8);
         fputs(tem.sex,fp_driver_information);
         printf("\t\t\t\t请输入职位:");
         my_fgets(tem.postion,MAX_BYTE );
         fputs(tem.postion,fp_driver_information);
         printf("\t\t\t\t请输入密码:");
         my_fgets(tem.secretcode,MAX_BYTE );
         secretcode_in(tem.secretcode);   //密码未加密处理 输入未清空
         fputs(tem.secretcode,fp_driver_information);
         printf("\t\t\t\t请输入注册日期:");
         my_fgets(tem.date,MAX_BYTE );
         fputs(tem.date,fp_driver_information);
         printf("\t\t\t\t请输入车型:");
         my_fgets(tem.car_type,MAX_BYTE );
         fputs(tem.car_type,fp_driver_information);
         printf("\t\t\t\t请输入车牌号:");
         my_fgets(tem.car_number,MAX_BYTE );
         fputs(tem.car_number,fp_driver_information);
         printf("\t\t\t\t请输入车辆颜色:");
         my_fgets(tem.car_color,MAX_BYTE);
         fputs(tem.car_color,fp_driver_information);
         printf("\t\t\t\t请输入手机号:");
         my_fgets(tem.phone_number,MAX_BYTE );
         fputs(tem.phone_number,fp_driver_information);
         fputs("\n",fp_driver_information);
         return _SUCCEES;
       
    }
   
   else printf("\n\n\t\t\t\t信息文件出现错误\n");
       return _FAIL;
}


int sign_up_manager()
{
    manager_info tem;
    FILE *fp_manager_information;
    if((fp_manager_information = fopen("manager_information","a+")) != NULL)
    {
         printf("\n\n\t\t\t\t请输入8位编号:");
         my_fgets(tem.manager_number,10 );
         fflush(stdin);
         fputs(tem.manager_number,fp_manager_information);
         printf("\t\t\t\t请输入姓名:");
         my_fgets(tem.name,MAX_BYTE );
         fputs(tem.name,fp_manager_information);
         printf("\t\t\t\t请输入性别（female/male）:");
         my_fgets(tem.sex,8 );
         fputs(tem.sex,fp_manager_information);
         printf("\t\t\t\t请输入职位:");
         my_fgets(tem.postion,MAX_BYTE );
         fputs(tem.postion,fp_manager_information);
         printf("\t\t\t\t请输入密码:");
         my_fgets(tem.secretcode,MAX_BYTE );
          secretcode_in(tem.secretcode);  
         fputs(tem.secretcode,fp_manager_information);
         printf("\t\t\t\t请输入注册日期:");
         my_fgets(tem.date,MAX_BYTE );
         fputs(tem.date,fp_manager_information);
        return _SUCCEES;
    }
    else printf("\n\n\t\t\t\t信息文件出现错误\n");
    sleep(1);
    return _FAIL;
}
