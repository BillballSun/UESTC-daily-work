#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "databaseADT.h"

#define Date_to_string_length 60

/******************************************************
 *year means 2017+year, and month/day mean the same
 *the max year mean 2017+65533
 ******************************************************/
struct locate_date
{
	unsigned short year;
	unsigned int month:4;
	unsigned int day:5;
	unsigned int hour:5;
	unsigned int min:6;
	unsigned int sec:6;
};

struct information
{
	unsigned char info_length;/*0-USHRT_MAX, 0-255*/
	char *info;
};

struct locate_url
{
	unsigned char url_length;/*0-USHRT_MAX, 0-255*/
	char *url;
};

struct item
{
	struct
	{
		struct locate_date input, modify;
	}date;
	struct
	{
		char name[Item_name_length+1];
		unsigned long store_amount;
		unsigned long saled_amount;
		double price;
	}basic;
	struct information info;
};

struct database
{
	struct item **data;
	size_t amount;/*0-SIZE_MAX*/
	struct locate_date create_date;
	struct information info;
	struct locate_url url;
};

static void Fill_present_time(struct locate_date *date);
static int Attach_item_to_database(Data database,struct item *new_item);
static struct item *Find_item_by_name(Data database, char *name);
static struct item *Duplicate_item(struct item *source);
static bool *Search_item(Data database, int (*correct)(struct item *), bool *result);
static char *Conert_struct_locate_date_to_string(struct locate_date *date);

/******************************************************
 *Loading database steps
 *database->info->item->info
 *if open and load failed return NULL
 *After reading data fclose automatically
 ******************************************************/
Data Loading_database(char *url)
{
	FILE *fp;
	if((fp=fopen(url, "rb+"))==NULL) return NULL;
	Data database;
	if((database=(Data)malloc(sizeof(struct database)))==NULL)
	{
		return NULL;
		fclose(fp);
	}
	if(fread(database, sizeof(struct database), 1, fp)==0)
	{
		free(database);
		fclose(fp);
		return NULL;
	}
	if(database->info.info_length==0)
		database->info.info=NULL;
	else
	{
		if((database->info.info=(char *)malloc(database->info.info_length+1))==NULL)
		{
			free(database);
			fclose(fp);
			return NULL;
		}
		if(fread(database->info.info, database->info.info_length+1, 1, fp)==0)
		{
			free(database->info.info);
			free(database);
			fclose(fp);
			return NULL;
		}
	}
	database->url.url_length=strlen(url);
	if((database->url.url=(char *)malloc(database->url.url_length+1))==NULL)
	{
		free(database->info.info);
		free(database);
		fclose(fp);
		return NULL;
	}
	strncpy(database->url.url, url, database->url.url_length+1);
	if(database->amount==0)
		database->data=NULL;
	else
	{
		if((database->data=(struct item **)malloc(database->amount*sizeof(struct item *)))==NULL)
		{
			free(database->info.info); /*If it points to NULL, it does nothing*/
			free(database);
			fclose(fp);
			return NULL;
		}
		for(size_t i=1;i<=database->amount;i++)
		{
			if((database->data[i-1]=(struct item *)malloc(sizeof(struct item)))==NULL)
			{
				for(size_t t=1;t<=i-1;t++)
					free(database->data[t-1]->info.info);
				for(size_t t=1;t<=i-1;t++)
					free(database->data[t-1]);
				free(database->info.info);
				free(database);
				fclose(fp);
				return NULL;
			}
			if(fread(database->data[i-1],sizeof(struct item), 1, fp)==0)
			{
				for(size_t t=1;t<=i-1;t++)
					free(database->data[t-1]->info.info);
				for(size_t t=1;t<=i;t++)
					free(database->data[t-1]);
				free(database->info.info);
				free(database);
				fclose(fp);
				return NULL;
			}
			if (database->data[i - 1]->info.info_length != 0)
			{
				if ((database->data[i - 1]->info.info = (char *)malloc(database->data[i - 1]->info.info_length + 1)) == NULL)
				{
					for (size_t t = 1; t <= i - 1; t++)
						free(database->data[t - 1]->info.info);
					for (size_t t = 1; t <= i; t++)
						free(database->data[t - 1]);
					free(database->info.info);
					free(database);
					fclose(fp);
					return NULL;
				}
				if(fread(database->data[i-1]->info.info, database->data[i-1]->info.info_length+1, 1, fp)==0)
				{
					for(size_t t=1;t<=i;t++)
						free(database->data[t-1]->info.info);
					for(size_t t=1;t<=i;t++)
						free(database->data[t-1]);
					free(database->info.info);
					free(database);
					fclose(fp);
					return NULL;
				}
			}
			else
				database->data[i - 1]->info.info = NULL;
		}
	}
	fclose(fp);
	return database;
}

/******************************************************
 *Saving data to file
 *if it failed due to open/create it or writing error
 *return EOF else return zero and clean the file
 *If url equals NULL try to use url in the database
 ******************************************************/
int Saving_database(Data database, char *url)
{
	FILE *fp;
	if(url==NULL) url=database->url.url;
	if((fp=fopen(url, "wb"))==NULL) return EOF;
	if(fwrite(database, sizeof(struct database), 1, fp)==0)
	{
		fclose(fp);
		remove(url);
		return EOF;
	}
	if (database->info.info_length!=0)
		if(fwrite(database->info.info, database->info.info_length+1, 1, fp)==0)
		{
			fclose(fp);
			remove(url);
			return EOF;
		}
	for(size_t i=1;i<=database->amount;i++)
	{
		if(fwrite(database->data[i-1],sizeof(struct item), 1, fp)==0)
		{
			fclose(fp);
			remove(url);
			return EOF;
		}
		if (database->data[i-1]->info.info_length!=0)
			if(fwrite(database->data[i-1]->info.info, database->data[i-1]->info.info_length+1, 1, fp)==0)
			{
				fclose(fp);
				remove(url);
				return EOF;
			}
	}
	fclose(fp);
	return 0;
}

/******************************************************
 *Generate a new database, if failed return NULL
 *else return pointer to the new_database
 ******************************************************/
Data Generate_database(void)
{
	Data database;
	if((database=(Data)malloc(sizeof(struct database)))==NULL) return NULL;
	database->data=NULL;
	database->amount=0;
	database->info.info_length=0;
	database->info.info=NULL;
	database->url.url_length=0;
	database->url.url=NULL;
	Fill_present_time(&database->create_date);
	return database;
}

void Destroy_database(Data database)
{
	for(size_t i=1;i<=database->amount;i++)
	{
		free(database->data[i-1]->info.info);
		free(database->data[i-1]);
	}
	free(database->info.info);
	free(database->url.url);
	free(database);
}

int Destory_item(Data database, size_t ID)
{
	if(Get_database_amount(database)<ID) return EOF;
	free(database->data[ID-1]->info.info);
	free(database->data[ID-1]);
	return 0;
}

/******************************************************
 *If it failed the return EOF
 *else return zero
 ******************************************************/
int Adding_item(Data database, char *name, unsigned long amount, double price)
{
	if(database->amount==SIZE_MAX) return EOF;
	struct item *new_item;
	if((new_item=(struct item *)malloc(sizeof(struct item)))==NULL) return EOF;
	struct item **temp;
	if((temp=(struct item **)realloc(database->data, sizeof(struct item *)*++database->amount))==NULL)
	{
		free(new_item);
		return EOF;
	}
	database->data=temp;
	database->data[database->amount-1]=new_item;
	strncpy(new_item->basic.name, name, Item_name_length);
	new_item->basic.name[Item_name_length]='\0';
	Fill_present_time(&new_item->date.input);
	Fill_present_time(&new_item->date.modify);
	new_item->basic.store_amount=amount;
	new_item->basic.saled_amount=0;
	new_item->basic.price=price;
	new_item->info.info_length=0;
	new_item->info.info=NULL;
	return 0;
}

/******************************************************
 *If not existing return 0
 *else return ID from 1 -- SIZE_MAX
 ******************************************************/
size_t Get_item_ID(Data database, char *name)
{
	for(size_t i=1;i<=database->amount;i++)
		if(strcmp(database->data[i-1]->basic.name, name)==0) return i;
	return 0;
}

Data Combine_two_file(char *url_1, char *url_2)
{
	Data result, second;
	if((result=Loading_database(url_1))==NULL) return NULL;
	if((second=Loading_database(url_2))==NULL)
	{
		Destroy_database(result);
		return NULL;
	}
	struct item *item_p;
	for(size_t i=1;i<=second->amount;i++)
	{
		if((item_p=Find_item_by_name(result, second->data[i-1]->basic.name))==NULL)
		{
			struct item *temp=Duplicate_item(second->data[i-1]);
			if(temp==NULL)
			{
				Destroy_database(second);
				Destroy_database(result);
				return NULL;
			}
			if(Attach_item_to_database(result, temp)==EOF)
			{
				free(temp);
				Destroy_database(second);
				Destroy_database(result);
				return NULL;
			}
		}
		else
		{
			item_p->basic.store_amount+=second->data[i-1]->basic.store_amount;
			item_p->basic.saled_amount+=second->data[i-1]->basic.saled_amount;
		}
	}
	Destroy_database(second);
	return result;
}

unsigned long Sale_product_by_ID(Data database, size_t ID, unsigned long amount)
{
	if(ID==0||ID>database->amount) return 0;
	unsigned long *store=&database->data[ID-1]->basic.store_amount,
				  *saled=&database->data[ID-1]->basic.saled_amount;
	if(amount>=*store)
	{
		*store=0;
		*saled+=amount;
	}
	else
	{
		*store-=amount;
		*saled+=amount;
	}
	Fill_present_time(&database->data[ID - 1]->date.modify);
	return *store;
}

int Check_database(Data database, int mode)
{
	if(mode!=Check_repair&&mode!=Check_result) return -1;
	int error=0;
	if(database->info.info_length!=0)
		if(database->info.info[database->info.info_length]!='\0')
		{
			if(mode==Check_repair)database->info.info[database->info.info_length]='\0';
			error++;
		}
	if(database->url.url_length!=0)
		if(database->url.url[database->url.url_length]!='\0')
		{
			if(mode==Check_repair)database->url.url[database->url.url_length]='\0';
			error++;
		}
	for(size_t i=1;i<=database->amount;i++)
		if(database->data[i-1]->info.info[database->data[i-1]->info.info_length]!='\0')
		{
			if(mode==Check_repair)database->data[i-1]->info.info[database->data[i-1]->info.info_length]='\0';
			error++;
		}
	return error;
}

/******************************************************
 *if error occured return -1
 *else return zero
 ******************************************************/
int Adding_info_to_database(Data database, char *info)
{
	free(database->info.info);
	database->info.info_length=strlen(info);
	if((database->info.info=(char *)malloc(database->info.info_length+1))==NULL) return -1;
	strncpy(database->info.info, info, database->info.info_length);
	database->info.info[database->info.info_length]='\0';
	return 0;
}

/******************************************************
 *If error occured return -1
 *else return zero
 ******************************************************/
int Adding_info_to_item(Data database, size_t ID, char *info)
{
	if(ID==0||ID>database->amount) return -1;
	free(database->data[ID-1]->info.info);
	database->data[ID-1]->info.info_length=strlen(info);
	if((database->data[ID-1]->info.info=(char *)malloc(database->data[ID-1]->info.info_length+1))==NULL) return -1;
	strncpy(database->data[ID-1]->info.info, info, database->data[ID-1]->info.info_length);
	database->data[ID-1]->info.info[database->data[ID-1]->info.info_length]='\0';
	return 0;
}

char *Get_database_info(Data database)
{
	if(database->info.info_length==0) return NULL;
	return database->info.info;
}

char *Get_item_info(Data database, size_t ID)
{
	if(database->amount<ID||database->data[ID-1]->info.info_length==0) return NULL;
	return database->data[ID-1]->info.info;
}

size_t Get_database_amount(Data database)
{
	return database->amount;
}

char *ALLOCATE_database_create_date(Data database)
{
	return Conert_struct_locate_date_to_string(&database->create_date);
}

char *ALLOCATE_item_input_date(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return Conert_struct_locate_date_to_string(&database->data[ID-1]->date.input);
}

char *ALLOCATE_item_modify_date(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return Conert_struct_locate_date_to_string(&database->data[ID-1]->date.modify);
}

char *Get_item_name(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return database->data[ID-1]->basic.name;
}

unsigned long Get_item_store_amount(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return database->data[ID-1]->basic.store_amount;
}

unsigned long Get_item_saled_amount(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return database->data[ID-1]->basic.saled_amount;
}

double Get_item_price(Data database, size_t ID)
{
	if(ID>database->amount) return NULL;
	return database->data[ID-1]->basic.price;
}

/******************************************************
 *Get_item_date
 *if error happens return EOF else return zero
 *if one date_object is not needed, just type NULL is OK!
 ******************************************************/
int Get_item_date(Data database, size_t ID, int mode, int *year, int *month, int *day, int *hour, int *min, int *sec)
{
	if(database==NULL||Get_database_amount(database)<ID) return EOF;
	if(mode!=GET_item_date_input&&mode!=GET_item_date_modify) return EOF;
	struct locate_date *date_p;
	switch(mode)
	{
		case GET_item_date_input:date_p=&database->data[ID-1]->date.input;break;
		case GET_item_date_modify:date_p=&database->data[ID-1]->date.modify;break;
		default:return EOF;
	}
	if(year!=NULL) *year=date_p->year;
	if(month!=NULL) *month=date_p->month;
	if(day!=NULL) *day=date_p->day;
	if(hour!=NULL) *hour=date_p->hour;
	if(min!=NULL) *min=date_p->min;
	if(sec!=NULL) *sec=date_p->sec;
	return 0;
}

static void Fill_present_time(struct locate_date *date)
{
	time_t rawtime;
	time(&rawtime);
	struct tm *local=localtime(&rawtime);
	if(local->tm_year+1900<2017) date->year=0;
	else date->year=local->tm_year+1900-2017;
	date->month=local->tm_mon+1;
	date->day=local->tm_mday;
	date->hour=local->tm_hour;
	date->min=local->tm_min;
	date->sec=local->tm_sec;
}

static int Attach_item_to_database(Data database,struct item *new_item)
{
	if(database->amount==SIZE_MAX) return EOF;
	struct item **temp;
	if((temp=(struct item **)realloc(database->data, sizeof(struct item *)*++database->amount))==NULL) return EOF;
	database->data=temp;
	database->data[database->amount-1]=new_item;
	return 0;
}

static struct item *Find_item_by_name(Data database, char *name)
{
	for(size_t i=1;i<=database->amount;i++)
		if(strcmp(database->data[i-1]->basic.name, name)==0) return database->data[i-1];
	return NULL;
}

/******************************************************
 *it allocate an array of bool length is amount
 *if something error occured return NULL
 *if item stays function CORRECT must return zero
 ******************************************************/
static bool *Search_item(Data database, int (*correct)(struct item *), bool *result)
{
	if(database->amount==0) return NULL;
	if(result==NULL)
	{
		if((result=(bool *)malloc(database->amount))==NULL) return NULL;
		for(bool *temp=result;temp<=result+database->amount-1;temp++)
			*temp=true;
	}
	for(size_t i=1; i<=database->amount;i++)
		if(result[i-1]&&(*correct)(database->data[i-1])!=0)
			result[i-1]=false;
	return result;
}

static char *Conert_struct_locate_date_to_string(struct locate_date *date)
{
	char *result;
	if((result=(char *)malloc(Date_to_string_length+1))==NULL) return NULL;
	const char *months[]={
					"January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December"
				  };
	char *day_last;
	switch(date->day%10)
	{
		case 1:day_last="st";
		case 2:day_last="nd";
		case 3:day_last="rd";
		default:day_last="th";
	}
	/*EXAMPLE as below*/
	/*Date: January 25th 2017 20:31:41*/
	sprintf(result, "Date: %s %u%s %hu %u:%u:%u",
	months[date->month-1], date->day, day_last, date->year+2017, date->hour, date->min, date->sec);
	return result;
}

static struct item *Duplicate_item(struct item *source)
{
	typedef struct item *Item;
	Item result;
	if ((result = (Item)malloc(sizeof(struct item))) == NULL)
		return NULL;
	*result = *source;
	if ((result->info.info = (char *)malloc(result->info.info_length + 1)) == NULL)
	{
		free(result);
		return NULL;
	}
	strncpy(result->info.info, source->info.info, result->info.info_length);
	result->info.info[result->info.info_length] = '\0';
	return result;
}