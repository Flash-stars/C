#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
struct message{
		int lines;
		int words;
		int max_line_length;
		int size;
		int chars;
}info;
void error_print(char str[]){
		printf("Error:%s",str);
}
void init(char filename[]){
		struct stat get_message = {};
		FILE *fp;
		int ret_stat = stat(filename,&get_message);
		if(ret_stat == -1){
				error_print(filename);
				return ;
		}
		mode_t mode = get_message.st_mode;
		int length = 0;
		if(S_ISDIR(mode))
				printf("Error %s is dir\n0\t0\t0\t%s",filename,filename);
		else{
				info.size = get_message.st_size;
				fp = fopen(filename,"r");
				char ch;
				int flag = 0;
				while((ch = fgetc(fp))!=EOF){	
						info.chars++;
 
						if(ch != '\n'){
 
								length++;
						}
						if(ch == '\n'){
								info.lines ++;
								if(length>info.max_line_length)
										info.max_line_length = length;
								length = 0;
						}
						if(ch == '\t' || ch == ' ' || ch == '\n'){
								flag = 0;
								continue;
						}
						else{
 
								if(flag == 0){
										info.words++;
										flag = 1;
								}
						}
				}
				fclose(fp);
		}
 
}

void EmptyFile(){
		char ch;
		int flag = 0;
		int length = 0;
 
		while((ch = getchar())!=EOF){
				info.chars++;
				info.size += sizeof(ch);
				if(ch != '\n'){
						length++;
				}
				if(ch == '\n'){
						info.lines ++;
						if(length>info.max_line_length)
								info.max_line_length = length;
						length = 0;
				}
				if(ch == '\t' || ch == ' ' || ch == '\n'){
						flag = 0;
						continue;
				}
				else{
 
						if(flag == 0){
								info.words++;
								flag = 1;
						}
				}
 
		}
}
int main(int argc,char *argv[]){
 
		if(argc == 2){
				if(argv[1][0] != '-'){
						init(argv[1]);
						printf("%d %d %d %s\n",info.lines,info.words,info.size,argv[1]);
						return 0;
				}
				else{
						EmptyFile();
 
				}
		}
		else if(argc == 1){
				EmptyFile();
				printf("%d\t%d\t%d\n",info.lines,info.words,info.size);
				return 0;
		}
		else if(argc == 3){
				init(argv[2]);
		}
		int num;
		while((num = getopt(argc,argv,"lwmcL"))!=-1){
				switch(num){
						case 'l':
								printf("%d\t",info.lines);
								break;
						case 'w':
								printf("%d\t",info.words);
								break;
						case 'm':
								printf("%d\t",info.chars);
								break;
						case 'c':
								printf("%d\t",info.size);
								break;
						case 'L':
								printf("%d\t",info.max_line_length);
								break;
				}
		}
		if(argc != 2 && argv[1][0] != '-')
				printf("%s\n",argv[2]);
 
 
		return 0;
}
 
