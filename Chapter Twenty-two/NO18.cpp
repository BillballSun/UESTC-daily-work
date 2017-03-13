/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#define Initialized_storage 100
#define Max_data_storage 10000

/* language change */
#define LOOP for(;;)

void Safe_read_line(char *s, size_t len);
int Compare_two_int(const void *first, const void *second);

int main(int argc, char *argv[])
{
	int *main_storage=NULL;
	size_t storage_size=0u, present_amount=0u;
	fprintf(stdout, "Please input the file url:");
	char url[FILENAME_MAX];
	Safe_read_line(url, FILENAME_MAX-1);
	FILE *fp;
	if((fp=fopen(url, "r"))==NULL)
	{
		fprintf(stderr, "ERROR: file opened failed.\n");
		system("pause");
		return EXIT_FAILURE;
	}
	int temp;
	LOOP
	{
		if(fscanf(fp, "%d", &temp)<1)
			break;
		if(present_amount==storage_size)
			if(storage_size<Max_data_storage)
			{
				int *pointer=(int *)realloc(main_storage, sizeof(int)*(storage_size+Initialized_storage));
				if(pointer==NULL) break;
				main_storage=pointer;
				storage_size+=Initialized_storage;
			}
			else break;
		main_storage[present_amount++]=temp;
	}
	qsort(main_storage, present_amount, sizeof(int), Compare_two_int);
	#if defined _WIN32
	if(present_amount%2==0)
		fprintf(stdout, "We got %u digits, the average is %d.\n", present_amount, (main_storage[present_amount/2-1]+main_storage[present_amount/2])/2);
	else
		fprintf(stdout, "We got %u digits, the average is %d.\n", present_amount, main_storage[present_amount/2]);
	#elif defined _WIN64
	if(present_amount%2==0)
		fprintf(stdout, "We got %u digits, the average is %d.\n", present_amount, (main_storage[present_amount/2-1]+main_storage[present_amount/2])/2);
	else
		fprintf(stdout, "We got %u digits, the average is %d.\n", present_amount, main_storage[present_amount/2]);
	#else
		#error WIN32 or WIN64 compiler required
	#endif
	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}

int Compare_two_int(const void *first, const void *second)
{
	int st=*(int *)first, nd=*(int *)second;
	if(st==nd) return 0;
	if(st>nd) return 1;
	else return -1;
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
