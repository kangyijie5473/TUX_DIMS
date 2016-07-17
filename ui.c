/*************************************************************************
	> File Name: ui.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月29日 星期三 09时47分00秒
 ************************************************************************/

#include<stdio.h>

void welcome(void)
{ 
                
printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                              ########  #f     #    #     #     \n");                    
    printf("\t\t                                 #L     #f     #    ##   #i      \n" );                   
    printf("\t\t                                 #L     #f     #     #  D#       \n " );                   
    printf("\t\t                                 #L     #f     #     ,# #        \n " );                   
    printf("\t\t                                 #L     #f     #      ###          \n" );                  
    printf("\t\t                                 #L     #f     #      ##j          \n " );                 
    printf("\t\t                                 #L     #L     #      #t#          \n " );                 
    printf("\t\t                                 #L     ##     #     #  ##         \n" );                  
    printf("\t\t                                 #L     :#    G#    ##   #         \n" );                  
    printf("\t\t                                 #L      ##i ##i   .#    ##        \n" );                  
    printf("\t\t                                 #L       ####     ##     #D       \n " );
    printf("\t\t                                                         \n ");
    printf("\t\t                                                       \n ");
    printf("\t\t                             Drivers' Information Management System \n" );
	printf("\t\t                                                         \n "); 
	printf("\t\t                                                         \n ");
    printf("\t\t	                                          Designed by D.Kang \n");
	 printf("									                     \n ");
      printf("                                                       \n"); 
    getchar();
}
int choose_user_in(void) //bug 输入非法时 提示信息会多出现一次
{
    int key;
    char choice[3];
    char user_in_number[MAX_BYTE];
    system("clear");
    while(1)
    {
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t                                  您的身份是？（以输入的第一位为准）\n");
    printf("\t\t\t                                ♣ 1.管理员\n");
    printf("\t\t\t                                ♣ 2.司机\n");
    printf("\t\t\t                                ♣ 0.返回上一级\n");
    setbuf(stdin,NULL);
    printf("                                        ");
    fgets(choice,3,stdin);
    system("clear");
    setbuf(stdin,NULL);
        switch(choice[0])
    {
        case '1':system("clear");if(sign_in_manager()) choose_manager_features() ;
        case '2':system("clear");if(sign_in_driver(user_in_number)) printf("您可以修改自己的信息了\n");change_driver_self(user_in_number); sleep(3);exit(1);
        case '0':if(choose_in_up()) return 1;else return 0;
        default :printf("                   输入非法\n");
    }
      setbuf(stdin,NULL);
    }
}
int choose_user_up(void) //bug 输入非法时 提示信息会多出现一次
{
    int key;
    char choice[3];
    system("clear");
    while(1)
    {
    system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                                 您的身份是？（以输入的第一位为准）\n");
    printf("\t\t                               ♦ 1.管理员\n");
    printf("\t\t                               ♦ 2.司机\n");
    printf("\t\t                               ♦ 0.返回上一级\n");
    setbuf(stdin,NULL);
    printf("                                        ");
        fgets(choice,3,stdin);
        switch(choice[0])
    {
        case '1':if(sign_up_manager()) choose_in_up();else printf("error\n");sleep(6);choose_in_up();
        case '2':if(sign_up_driver())  choose_in_up();else printf("error\n");sleep(6);choose_in_up();
        case '0':if(choose_in_up())  choose_in_up();else printf("error\n");sleep(6);choose_in_up();
        default :printf("输入非法\n");
    }
    }
}
int  choose_in_up()
{
    char choice[5];
    system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t                                请输入您的选择\n");
    printf("\t\t\t                               ♠ 1.登陆\n");
    printf("\t\t\t                               ♠ 2.注册\n");
    printf("\t\t\t                               ♠ 0.退出程序\n");
    setbuf(stdin,NULL);
    printf("                                        ");
    fgets(choice,5,stdin);
    switch(choice[0])
    {
        case '1':if( choose_user_in())  return 1; else return -1;
        case '2':if( choose_user_up())  ; else return -2;
        case '0':printf("\n\n\t\t\t\t请再次确认(y/n)\n            "); if(getchar() == 'y') {getchar();exit(0);}else choose_in_up();
        default :printf("\n\n\t\t\t\t输入非法！！！系统退出\n");exit(1);
    }
}

int choose_sort(driver_info *phead)
{
    char k[3];
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                   您想按什么顺序查看？\n");
    printf("\t\t                   1. 升序\n");
    printf("\t\t                   2. 降序\n");
    printf("\n\n");
    printf("                        ");
    fgets(k,3,stdin);
    switch(k[0])
    {
        case '1':BubbleSort_down(phead);break;
        case '2':BubbleSort_up(phead);break;
        default :choose_sort(phead);
    }
    return _SUCCEES;
}

int  choose_manager_features()
{
    driver_info *phead;
    char choice[3];
    phead = file_to_mem();
    if (phead->next == NULL)
    {printf("\n\n\t\t\t\t信息文件无记录，请新建，在学号处输入end回车结束\n");
     phead = entry_driver_information();
     mem_to_file(phead);
    }

    while(1)
    {  
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t                                         您想做什么？\n");
    printf("\n\n");
    printf("\t\t                                  1. 查看现有司机全部信息\n");
    printf("\t\t                                  2. 新建一个司机信息\n");
    printf("\t\t                                  3. 删除一个司机信息\n");
    printf("\t\t                                  4. 修改一个司机信息\n");
    printf("\t\t                                  5. 精确查询司机信息\n");
    printf("\t\t                                  6. 模糊查询司机信息\n");
    printf("\t\t                                  7. 排序查看司机信息\n");
    printf("\t\t                                  8. 统计查看司机信息\n");
    printf("\t\t                                  9. 返回上一级菜单\n");
    printf("\t\t                                  0. 退出程序\n");
    printf("\t\t                                  x. 删除所有信息\n");
    printf("\t\t                                  n. 新建所有信息\n");
    printf("\t\t                                   ");
        fgets(choice,3,stdin);
        switch(choice[0])
    {
        case '1':system("clear");printf("\n\n\n\n\n\n\n\n\n\n\n");print(phead);printf("\n\n\n                                按任意键返回前一级菜单\n");getchar();continue;
        case '2':create_new_driver(phead);free(phead); choose_manager_features(); 
        case '3':delete_old_driver(phead); free(phead);choose_manager_features();
        case '4':change_old_driver(phead); free(phead);choose_manager_features();
        case '5':search_simple_car_number(phead) ;free(phead);choose_manager_features();
        case '6':search_vague_car_color_type(phead);free(phead); choose_manager_features();
        case '7':choose_sort(phead);print(phead);printf("\n\n\t\t\t\t按任意键返回前一级菜单");getchar();free(phead);choose_manager_features();
        case '8':count(phead);printf("\n\n\t\t\t\t按任意键返回前一级菜单");getchar();free(phead); choose_manager_features();
        case '9':free(phead);choose_user_in() ; 
        case '0':printf("\n\n\t\t\t\t确认退出？(y/n)\n            ");if(getchar() == 'y') {free(phead);exit(0);}else {printf("\n\n\t\t\t\t按任意键返回前一级菜单");getchar(); choose_manager_features();}
        case 'x':system("clear");printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t  请再次确认！！！(y/n)\n");if(getchar() == 'y') {system("rm driver_information");exit(1);}else { printf("\n\n\t\t\t\t按任意键返回前一级菜单");getchar();choose_manager_features();}
        case 'n':  phead = entry_driver_information();mem_to_file(phead);exit(1);
        default :continue;
    }
    }
}
