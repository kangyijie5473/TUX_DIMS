/*************************************************************************
	> File Name: secretcode_int.c
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 12时12分39秒
 ************************************************************************/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char * secretcode_in(char secretcode[])
{
    int i;
    for(i = 0; i < strlen(secretcode)-1; i++)
    {
        secretcode[i] += i;                  //加密 每位加上位数
    }

    //fputs(secretcode,stdout);
      //for(i = 0; i < strlen(secretcode)-1; i++)
   // secretcode[i] -= i;
   // fputs(secretcode,stdout);
    return secretcode;
}
int main(void)
{
    int i;
    char secretcode[22],*secretcode_out;
    secretcode_out = (char *)malloc(sizeof(char)*22);
    //fgets(secretcode,22,stdin);
    for(i = 0;;i++)
    {
        //printf("*");
        secretcode[i]= getchar();
        //secretcode[i] = fgetc(stdin);
        //scanf("%c",&secretcode[i]);
        if(secretcode[i] == '\n')
        {
            printf("\n");
            break;
        }
        printf("*");
    }

    secretcode_out = secretcode_in(secretcode);
    fputs(secretcode_out,stdout);
}

