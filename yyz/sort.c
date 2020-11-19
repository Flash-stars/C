#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pupple(int* p, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (p[j - 1] > p[j])
			{
				swap(&p[j - 1] , &p[j]);
			}
		}
	}
}
int main()
{
	int index = 0;
	int array[100] = { 0 };
	char buf[1000] = "";
	int i;
	char file[20]="";
	gets(file);
	FILE* p = fopen(file, "r");
	if (p == NULL)
	{
		printf("error!!!\n");
	}
	else
	{
		while (!feof(p))
		{
			memset(buf, 0, sizeof(buf));
			fgets(buf, sizeof(buf), p);
			array[index] = atoi(buf);
			index++;
		}
		fclose(p);
	}
	pupple(array, index);
	FILE* p1 = fopen("b.txt", "w");
	for (i = 1; i < index; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d\n", array[i]);
		fputs(buf,p1);
	}
	fclose(p1);
	return 0;
}

