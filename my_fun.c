void my_fgets(char array[],int len)
{
    int i;
    fgets(array,len,stdin);
    i = strlen(array)-1;
    array[i] = ' ';
    
}
void my_fscanf(FILE *fp,char array[])
{
    int i;
    fscanf(fp,"%s",array);
    i=strlen(array);
    array[i] = ' ';
    array[i+1] = '\0';
}
void secretcode_in(char secretcode[])
{
    int i;
    for(i = 0; i < strlen(secretcode)-1; i++)
    {
        secretcode[i] += i;                  //加密 每位加上位数
    }
    return ;
}
void secretcode_out(char secretcode[])
{
    int i;
    for(i = 0; i < strlen(secretcode)-1; i++)
    secretcode[i] -= i;
}
