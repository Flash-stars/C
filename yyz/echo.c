#include<stdio.h>
int main(int argc,char *arg[])
{
	int i;
	for(i=1;i<argc;i++)
		printf("%s%s",arg[i],(i<argc-1)?" ":"");
	printf("\n");
	return 0;
}
