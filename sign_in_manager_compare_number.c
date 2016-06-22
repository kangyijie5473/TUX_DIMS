/*************************************************************************
	> File Name: test.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 17时34分29秒
 ************************************************************************/
long sign_in_manager_compare_number(char user_in_number[])
{
   long postion;
   FILE *fp; 
   manager_info tem;
   if((fp = fopen("manager_information","r") ) != NULL)
   {
       while(1)
       {
       fgets(tem.manager_number,10,fp);
       fgets(tem.name,MAX_BYTE,fp);
       fgets(tem.sex,8,fp);
       fgets(tem.postion,MAX_BYTE,fp);
       fgets(tem.date,MAX_BYTE,fp);
       postion = ftell(fp);
       fgets(tem.secretcode,MAX_BYTE,fp);
        if(!strcmp(tem.manager_number,user_in_number))
            return postion;
        else if(_FAIL == feof(fp))
                return _FAIL;
           else continue;
       }
   }
   else printf("error");
}
