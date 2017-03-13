//PR10
while((ch=getc(source_fp))!=EOF)
	if(putc(ch, dest_fp)==EOF)
	{
		fprintf(stderr, "Writing to destination failed\n");
		fclose(source_fp);
		fclose(dest_Fp);
		system("pause");
		exit(EXIT_FAILURE);
	}

//PR12
int count_periods(cnst char *filename)
{
	FILE *fp
	int n=0, ch;
	if((fp=fopen(filename,"r"))!=NULL)
	{
		while((ch=fgetc(fp))!=EOF)
			if(ch=='.') n++;
		fclose(fp);
	}
	return n;
}

//PR13
int line_length(const char *filename, int line)
{
	FILE *fp;
	if((fp=fopen(filename, "r"))==NULL) return -1;
	int ch;
	while(line>1&&((ch=getc(fp))!=EOF))
		if(ch=='\n') line--;
	if(line>1)
	{
		fclose(fp);
		return 0;
	}
	int result=0;
	while(((ch=getc(fp))!=EOF)&&ch!='\n') result++;
	return result;
}


//PR14
char *fgets(char *s, int n, FILE *stream)
{
	int i=0,ch;
	while(i<(n-1)&&(ch=getc(stream))!=EOF&&ch!='\n')
		s[i++]=ch;
	if(i>=(n-1))
	{
		*s='\n';
		return s;
	}
	if(ch==EOF)
	{
		if(ferr(stream))
		{
			s[i]='\0';
			return NULL;
		}
		else
		{
			s[i]='\0';
			if(i==0) return NULL;
			else return s;
		}
	}
	else
	{
		s[i++]='\n';
		s[i]='\0';
		return s;
	}
}

char *fputs(const char *s, FILE *stream)
{
	int ch;
	do
	{
		ch=putc(*s++,stream);
	}while(ch!=EOF&&ch!='\0');
	if(ch==EOF) return EOF;
	else return ch;
}

//PR15
fseek(fp,n,SEEK_CUR);
fseek(fp,-64,SEEK_END);
fseek(fp,-64,SEEK_CUR);
fseek(fp, 64*2,SEEK_CUR);

//PR16
sscanf(str,"%*[^#]%[0123456789,]",sales_rank);
