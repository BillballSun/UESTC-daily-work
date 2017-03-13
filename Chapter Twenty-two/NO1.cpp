#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc<=1)
	{
		fprintf(stderr, "arguments were missing\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	for(int i=1;i<=argc-1;i++)
		if((fp=fopen(argv[i],"r"))==NULL)
			fprintf(stderr, "%s file can\'t be opened.\n", argv[i]);
		else
		{
			fprintf(stdin, "%s file can be opened.\n", argv[i]);
			fclose(fp);
		}
	system("pause");
	return EXIT_SUCCESS;
}