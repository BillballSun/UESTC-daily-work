#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include <stdlib.h>

/* Macro function defination */
#define Clear_stdin() while(getc(stdin)!='\n')

void Safe_read_line(char *s, size_t len);

int main(void)
{
	char NO1[FILENAME_MAX];
	fprintf(stdout, "NO1 url:");
	Safe_read_line(NO1, FILENAME_MAX-1);
	char NO2[FILENAME_MAX];
	fprintf(stdout, "NO2 url:");
	Safe_read_line(NO2, FILENAME_MAX-1);
	FILE *fp1=fopen(NO1, "rb"), *fp2=fopen(NO2, "rb");
	if(fp1==NULL||fp2==NULL) return EXIT_FAILURE;
	int ch1, ch2;
	size_t main_count=0u,error_count=0u;
	while(((ch1=getc(fp1))!=EOF)&&((ch2=getc(fp2))!=EOF))
	{
		main_count++;
		if(ch1!=ch2) fprintf(stderr, "ERROR NO%u file1 got %d file2 got %d at data NO%u.\n", ++error_count, ch1, ch2, main_count);
	}
	fprintf(stdout, "FILE has %u data all\n", main_count);
	if(ch1!=EOF) fprintf(stderr, "file2 end before file1.\n");
	if((ch2=getc(fp2))!=EOF) fprintf(stderr, "file1 end before file2.\n");
	system("pause");
	return EXIT_SUCCESS;
}

void Safe_read_line(char *s, size_t len)
{
	char ch;
	while(((ch=getchar())!='\n')&&len>0)
	{
		*s++=ch;
		len--;
	}
	if(ch!='\n') Clear_stdin();
	*s='\0';
}