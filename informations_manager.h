/*************************************************************************
	> File Name: informations_manager.h
	> Author: Kangyijie 
	> Mail:Kangyijie5473@gmail.com 
	> Created Time: 2016年06月16日 星期四 18时59分15秒
 ************************************************************************/

#ifndef _INFORMATIONS_MANAGER_H
#define _INFORMATIONS_MANAGER_H
#define MAX_BYTE 22
typedef struct manager_information
{
    char manager_number[10];
    char name[MAX_BYTE];
    char sex[8];
    char postion[MAX_BYTE];
    char date[MAX_BYTE];
    char secretcode[MAX_BYTE];
    struct manager_information *pnext;
}manager_info;
#endif
