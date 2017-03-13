//NO1
double Round_nearest(double x, size_t n)
{
	double temp=1;
	for(size_t i=1; i<=n; i++)
		temp*=10;
	return round(x*temp)/temp;
}

//NO2
double Evaluate_polynomial(double *a, int n, double x)
{
	double temp=a[n];
	for(int i=n-1; n>=0; n--)
		temp=fma(temp, x, a[n-1]);
}

//NO4

#define Max_name_length 64

bool Check_spell(void)
{
	fprintf(stdout, "Please input a name:");
	int ch;
	char name[Max_name_length+1];
	size_t count=0;
	while((ch=getc(stdin))!='\n')
		if(count<Max_name_length)
			name[count++]=ch;
	name[count]='\0';
	size_t len=strlen(name);
	bool check=true;
	char *point=name;
	if(len>3)
		if((toupper(point[0])=='0'||toupper(point[0])=='O')&&toupper(point[1])=='X') point+=2;
	while(check&&*point)
	{
		if(!((*point>='0'&&*point<='9')||(toupper(*point)>='A'&&toupper(*point)<='F'))) check=false;
		point++;
	}
	return check;
}

//NO5
bool Check_xdigit_string(char *string)
{
	if(strlen(string)>=3)
		if((string[0]=='0'||toupper(string[0])=='O')&&toupper(string[1])=='X') string+=2;
	bool check=true;
	while(check&&*string)
	{
		if(!((*string>=0&&*string<=9)||(toupper(*string)>='A'&&toupper(*string)<='F')))
			check=false;
		string++;
	}
}

//NO6
(a)memmove
(b)memmove
(c)strncpy
(d)memcpy

//NO7
p=strchr(p+1, 'f');
the answer is nope

//NO8
int numchar(const char *str, char ch)
{
	int count=0;
	str--;
	while(str=strchr(str+1, ch)) count++;
	return count;
}

//NO9
if(strchr("abc", ch))

//NO10
strstr("foo bar baz" ,str);
YES, _if black in str error may occur

//NO11
void Set_exclamation_mark(char *str, size_t back_len)
{
	size_t len=strlen(str);
	if(back_len>=len)
		memset(str, '!', len);
	else
		memset(str+len-back_len, '!', back_len);
}

//NO12
char *strdup(const char *str)
{
	char *result;
	if(result=(char *)malloc(strlen(str)+1)) return NULL;
	return strcpy(result, str);
}

int stricmp(const char *s1, const char *s2)
{
	while(toupper(*s1)==toupper(*s2++))
		if(*s1++=='\0') return 0;
	return *s1-*s2;
}

char *strlwr(char *str)
{
	char *temp=str;
	while(*temp)
	{
		*temp=tolower(*temp);
		temp++;
	}
	return str;
}

char *strupr(char *str)
{
	char *temp=str;
	while(*temp)
	{
		*temp=toupper(*temp);
		temp++;
	}
	return str;
}

char *strrev(char *str)
{
	size_t len=strlen(str);
	unsigned char *temp=str;
	size_t dest=len/2-1;
	for(size_t i=0; i<=dest; i++)
	{
		str[i]^=str[len-i-1];
		str[len-i-1]^=str[i];
		str[i]^=str[len-i-1];
	}
	return str;
}

//NO13

int count_words(char *sentence)
{
	int count=0;
	if(strtok(sentence, "")!=NULL) count++;
	while(strtok(NULL, "")!=NULL) count++;
	return count;
}
