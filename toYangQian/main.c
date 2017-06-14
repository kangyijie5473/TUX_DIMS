/*
 * > File Name: main.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月13日 星期二 22时22分37秒
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAIL -1
#define MAX_NAME  20
#define MAX_STU   20

#define ADD 1
#define DEL 2
#define CGE 3
#define F_NAME 4
#define F_NUM 5
#define SORT 6
#define PRT  7
#define EXIT 0

typedef struct {
    char name[MAX_NAME];
    int number;
    int score;
}student;

void print_student();
void print_choice();
int file2mem();
int mem2file();
int sort_score();
int change_student();
int find_number();
int find_name();
int add_student();
int delete_student();

int student_count = 0;
student stu[MAX_STU];

void print_choice()
{
    printf("请输入你的选择\n");
    printf("1.增加一个学生信息\n");
    printf("2.删除一个学生信息\n");
    printf("3.修改一个学生信息\n");
    printf("4.按照学生姓名查找\n");
    printf("5.按照学生学号查找\n");
    printf("6.按照学生成绩排序\n");
    printf("7.打印目前学生信息\n");
    printf("0.退出\n");
}
int file2mem()
{
    FILE *fp;
    int i = 0;
    fp = fopen("student_information.txt","r");
    while(fscanf(fp,"%s%d%d",stu[i].name,&stu[i].number,&stu[i].score) != EOF){
        i++;
    }
    student_count = i;
    fclose(fp);
    return 1;
}
int mem2file()
{
    FILE *fp;
    int i;
    fp = fopen("student_information.txt","w");
    for(i = 0; i < student_count; i++){
        fprintf(fp,"%s %d %d\n",stu[i].name,stu[i].number,stu[i].score);
    }
    fclose(fp);
    return 1;
}
int sort_score()
{
    int i,j;
    char buffer[MAX_NAME];
    int temp;
    for(i = 0; i < student_count; i++){
        for(j = 0; j < student_count -i; j++){
            if(stu[j].score < stu[j+1].score){
                strcpy(buffer, stu[j].name);
                strcpy(stu[j].name,stu[j+1].name);
                strcpy(stu[j+1].name,buffer);

                temp = stu[j].number;
                stu[j].number = stu[j+1].number;
                stu[j+1].number = temp;

                temp = stu[j].score;
                stu[j].score = stu[j+1].score;
                stu[j+1].score = temp;
            }
        }
    }
    print_student();
    
}
void print_student()
{
    int i ;
    for(i = 0; i < student_count; i++){
        printf("%s%d%d\n",stu[i].name,stu[i].number,stu[i].score);
    }
}
int change_student()
{
    int i;
    if((i = find_name()) != -1){
        printf("name:\n");  
        scanf("%s",stu[i].name);
        printf("number:\n");  
        scanf("%d",&stu[i].number);
        printf("score:\n");
        scanf("%d",&stu[i].score);
        mem2file();
        printf("change success\n");
        return 0;
    }else{
        printf("not find you want to change student\n");
    }

}
int delete_student()
{
    int i,j = 0 ;
    char dele_name[MAX_NAME];
    printf("delete_student name:\n");
    scanf("%s",dele_name);
    
    for(i = 0; i < student_count; i++){
        if(strcmp(stu[i].name, dele_name) == 0){
            for(j = i; j < student_count; j++){
                strcpy(stu[j].name,stu[j+1].name);
                stu[j].number = stu[j+1].number;
                stu[j].score = stu[j+1].score;
            }
            break;
        }
    }
    if(j){
        printf("delete success\n");
        mem2file();
        return 0;
    }else
        printf("not find\n");
    return 1;
}
int add_student()
{
    printf("name:\n");  
    scanf("%s",stu[student_count].name);
    printf("number:\n");  
    scanf("%d",&stu[student_count].number);
    printf("score:\n");
    scanf("%d",&stu[student_count].score);
    student_count++;
    mem2file();
    printf("success\n");
    return 1;
}
int find_name()
{
    char want_name[MAX_NAME];
    int i;
    printf("find name:\n");
    scanf("%s",want_name);
    for(i = 0; i< student_count; i++){
        if(strcmp(stu[i].name, want_name) == 0){
            printf("%s %d %d\n",stu[i].name,stu[i].number, stu[i].score);
            return i;
        }
    }
    printf("not find\n");
    return -1;

}
int find_number()
{   
    int want_num, i;
    printf("find num:\n");
    scanf("%d",&want_num);
    for(i = 0; i< student_count; i++){
        if(stu[i].number == want_num){
            printf("%s %d %d\n",stu[i].name,stu[i].number, stu[i].score);
            return 1;
        }
    }
    printf("not find\n");
    return -1;

}
int main(void)
{
    int choice;
    if(file2mem() == FAIL){
        printf("信息文件读取出错\n");
        return 1;
    }
    while(1){
        print_choice();
        scanf("%d",&choice);
        switch(choice){
            case ADD:
                add_student();break;
            case DEL:
                delete_student();break;
            case CGE:
                change_student();break;
            case F_NAME:
                find_name();break;
            case F_NUM:
                find_number();break;
            case SORT:
                sort_score();break;
            case PRT:
                print_student();break;
            case EXIT:
                return 0;
        }
        getchar();
        printf("请按任意继续\n");
        getchar();
    }
    
}
