/*************************************************************************
	> File Name: sign_in_manager_compare_secretcode.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月21日 星期二 19时10分32秒
 ************************************************************************/

int sign_in_manager_compare_secretcode(long postion,char user_in_secretcode[])
{
    FILE *fp;
    char secretcode[MAX_BYTE];
    if((fp = fopen("manager_information","r")) != NULL)
    {
        fseek(fp,postion,SEEK_SET);
        fgets(secretcode,MAX_BYTE,fp);
        if(!strcmp(secretcode,user_in_secretcode))
            return _SUCCEES;
        else return _FAIL;
    }
    else printf("informations file is error\n");
}
