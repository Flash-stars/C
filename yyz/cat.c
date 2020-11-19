
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");   
    int read_ret;
    if(argc < 2)  
    {
        printf("please input source file!\n");
    }
    if(fp == NULL)  
    {
        printf("open source %s failed!\n", argv[1]);
        return -1;
    }
    while(1)  
    {
        read_ret = fgetc(fp);  
        if(feof(fp))  
        {
            printf("read file %s endl\n",argv[1]);        
            break;
        }
        fputc(read_ret,stdout);  
    }
}
