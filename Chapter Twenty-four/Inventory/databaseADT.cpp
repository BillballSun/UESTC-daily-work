/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "databaseADT.h"
#include "useful_macro.h"

#define SUCCEED 0
#define FAILED -1
#define Allocate_info_length 105

/* free_null macro replacement */
#define free_null(x) if((x)!=NULL) free(x)

static void Clean_item_allocation(struct item *item_p);
static size_t Re_caculate_item_amount(const Database p);
static struct item_save Convert_item_to_savemode(struct item store);
static struct database_save Convert_database_to_savemode(struct database origin);

struct item
{
	char *name;
	size_t stored_amount;
	size_t saled_amount;
	double price;
	char *info;
	struct item *next;
};

struct database
{
	struct item *item_point;
	size_t item_amount;
	char *info;
};

struct item_save
{
	size_t stored_amount;
	size_t saled_amount;
	double price;
	size_t name_length;
	size_t info_length;
}

struct database_save
{
	size_t item_amount;
	size_t info_length;
}

Database *Generate_database(const char *info)
{
	Database p;
	if((p=(Database)malloc(sizeof (struct database)))==NULL) return NULL;
	p->item_point=NULL;
	p->item_amount=0u;
	if(info!=NULL)
		if((p->info=(char *)malloc(strlen(info)+1))==NULL)
		{
			free(p);
			return NULL;
		}
		else strcpy(p->info, info);
	else
		if((p->info=(char *)malloc(1))==NULL)
		{
			free(p);
			return NULL;
		}
		else stpcpy(p->info, "");
	return p;
}

void Remove_database(Database *p)
{
	size_t limit=p->item_amount;
	for(size_t i=1; i<=limit; i++)
		Delete_item(p, i);
	free_null(p->info);
	free(p);
}

int Test_database(const Database p)
{
	size_t count=0;
	struct item *temp;
	for(temp=p->item_point;temp;temp=temp->next)
		count++;
	if(count==p->item_amount) return SUCCEED;
	else return FAILED;
}

static size_t Re_caculate_item_amount(const Database p)
{
	size_t count=0;
	struct item *temp;
	for(temp=p->item_point;temp;temp=temp->next)
		count++;
	return count;
}

int Add_item(Database p, char *name, size_t stored_amount, size_t saled_amount, double price, char *info)
{
	struct item *new_one;
	char *new_name=NULL, *new_info=NULL;
	if((new_one=(struct item *)malloc(sizeof(struct item)))==NULL) return FAILED;
	if(!(name==NULL||name[0]='\0'))
		if((new_name=(char *)malloc(strlen(name)+1))==NULL)
		{
			free(new_one);
			return FAILED;
		}
		else strcpy(new_name, name);
	else
		if((new_name=(char *)malloc(1))==NULL)
		{
			free(new_one);
			return FAILED;
		}
		else strcpy(new_name, "");
	if(!(info==NULL||info[0]='\0'))
		if((new_info=(char *)malloc(strlen(info)+1))==NULL)
		{
			free(new_one);
			free_null(new_name);
			return FAILED;
		}
		else strcpy(new_info, info);
	else
		if((new_info=(char *)malloc(1))==NULL)
		{
			free(new_one);
			free_null(new_name);
			return FAILED;
		}
		else strcpy(new_info, "");
	new_one->name=new_name;
	new_one->info=new_info;
	new_one->stored_amount=stored_amount;
	new_one->saled_amount=saled_amount;
	new_one->price=price;
	struct item *temp=p->item_point;
	while(temp) temp=temp->next;
	temp=new_one;
	p->item_amount++;
	return SUCCEED;
}

static void Clean_item_allocation(struct item *item_p)
{
	free_null(item_p->info);
	free_null(item_p->name);
	free(item_p);
}

struct item *Locate_item(const Database p, size_t ID)
{
	struct item *temp=p->item_point;
	size_t count=1;
	while(count++<ID)
		temp=temp->next;
	return temp;
	
}

int Delete_item(Database p, size_t ID)
{
	if(Test_database(p)||Re_caculate_item_amount(p)<ID) return FAILED;
	struct item *temp, new_temp;
	if(ID==1)
	{
		temp=p->item_point->next;
		Clean_item_allocation(p->item_point);
		p->item_point=temp;
	}
	else
	{
		temp=Locate_item(p, ID-1);
		new_temp=temp->next->next;
		Clean_item_allocation(temp->next);
		temp->next=new_temp;
	}
	p->item_amount--;
	return SUCCEED;
}

size_t Search_item(const Database p, size_t count, char *name, size_t stored_amount, size_t saled_amount, double price, char *info, unsigned char search_mode)
{
	size_t limit=p->item_amount;
	struct item *temp;
	bool check;
	while(count<=limit)
	{
		temp=Locate_item(p, count);
		check=true;
		if(search_mode&Search_mode_name) 		 if(strcmp(name, temp->name)!=0) 		check=false;
		if(search_mode&Search_mode_store_amount) if(stored_amount!=temp->stored_amount) check=false;
		if(search_mode&Search_mode_saled_amount) if(saled_amount!=temp->saled_amount) 	check=false;
		if(search_mode&Search_mode_price) 		 if(price!=temp->price) 				check=false;
		if(search_mode&Search_mode_info) 		 if(strcmp(info, temp->info)) 			check=false;
		if(check) return count;
		count++;
	}
	return 0u;
}

char *Allocate_info_for_an_item(const Database p, size_t ID)
{
	char *result;
	char temp[46];
	if((result=(char *)malloc(sizeof(Allocate_info_length+1)))==NULL) return NULL;
	if(ID>9999999) strcpy(result, "TooLong");
	else
	{
		snprintf(temp, 16, "%7"Size_t_format_replacement, ID);
		strcpy(result, temp);
	}
	struct item *item_p=Locate_item(p, ID);
	strcat(result, "  ");
	if(item_p->name==NULL) strcat(result, "       NoName");
	else
	{
		snprintf(temp, 16, "%s", item_p->name);
		size_t len=strlen(temp);
		if(len>13)
		{
			strncat(result, temp, 12);
			strcat(result, "*");
		}
		else
		{
			for(size_t i=1; i<=13-len; i++) strcat(result, " ");
			strcat(result, temp);
		}
	}
	if(item_p->stored_amount>999999999) strcpy(result, "      TooMuch");
	else
	{
		snprintf(temp, 14, "%13"Size_t_format_replacement, item_p->stored_amount);
		strcpy(result, temp);
	}
	if(item_p->saled_amount>999999999) strcpy(result, "    TooMuch");
	else
	{
		snprintf(temp, 12, "%11"Size_t_format_replacement, item_p->stored_amount);
		strcpy(result, temp);
	}
	if(item_p->price>9999999.9) strcpy(result, "    TooMuch");
	else
	{
		strcat(result, "  ");
		snprintf(temp, 10, "  %9.1f", item_p->price);
		strcpy(result, temp);
	}
	strcat(result, "  ");
	if(strlen(item_p->info)>45)
	{
		strcat(result, temp, 44);
		strcat(result, "*");
	}
	else strcat(result, item_p->info);
	return result;
}

/*
     ID           Name       Stored      Saled      Price   Info
----------------------------------------------------------------
    324        Patatos           99         21        1.2   You find something I need.
9999999  Test this_kkk    999999999  999999999  9999999.9

TooLong  MyStringGets*      TooMuch    TooMuch    TooMuch   Your string is getting longer and longer hah*
----->7  ---------->13  -------->11  ------->9  ------->9
       >2             >2           >2         >2          >3
*/

size_t Get_database_item_amount(const Database p)
{
	return p->item_amount;
}

char *Get_database_info(const Database p)
{
	return p->info;
}

char *Get_item_name(const Database p, size_t ID)
{
	return Locate_item(p, ID)->name;
}

size_t Get_item_stored_amount(const Database p, size_t ID)
{
	return Locate_item(p, ID)->stored_amount;
}

size_t Get_item_saled_amount(const Database p, size_t ID)
{
	return Locate_item(p, ID)->saled_amount;
}

char *Get_item_info(const Database p, size_t ID)
{
	return Locate_item(p, ID)->info;
}

int Is_url_accepted(char *url)
{
	FILE *fp;
	if((fp=fopen(url, "rb"))!=NULL)
	{
		fclose(fp);
		return File_already_exist;
	}
	if((fp=fopen(url, "wb"))!=NULL)
	{
		fclose(fp);
		remove(url);
		return File_canbe_created;
	}
	return File_access_denied;
}

int Save_database(Database p, char *url)
{
	FILE *fp;
	if((fp=fopen(url, "wb"))==NULL) return FAILED;
	struct database_save db=Convert_database_to_savemode(*p);
	if(fwrite(&db, sizeof(struct database_save), 1, fp)==1)
		if(strlen(p->info)==0||(fwrite(p->info, strlen(p->info), 1, fp))==1)
		{
			size_t limit=p->item_amount;
			struct item_save temp;
			for(size_t i=1; i<=limit; i++)
			{
				temp=Convert_item_to_savemode(*Locate_item(p, i));
				if(fwrite(&temp, sizeof(struct item_save), 1, fp)==1)
					if(strlen(Locate_item(p, i)->name)==0||(fwrite(Locate_item(p, i)->name, strlen(Locate_item(p, i)->name), 1, fp))==1)
						if(strlen(Locate_item(p, i)->info)==0||(fwrite(Locate_item(p, i)->info, strlen(Locate_item(p, i)->info), 1, fp))==1)
							continue;
				fclose(fp);
				remove(url);
				return FAILED;	
			}
			fclose(fp);
			return SUCCEED;
		}
	fclose(fp);
	remove(url);
	return FAILED;
}

Database *Load_database(char *url)
{
	FILE *fp;
	if((fp=fopen(url, "rb"))==NULL) return NULL;
	Database *p;
	if((p=Generate_database())==NULL)
	{
		fclose(fp);
		return NULL;
	}
	struct database_save db;
	if(fread(&db, sizeof(struct database_save), 1, fp)!=1)
	{
		fclose(fp);
		Remove_database(p);
		return NULL;
	}
	p->item_amount=db.item_amount;
	if((p->info=(char *)malloc(db.info_length+1))==NULL)
	{
		fclose(fp);
		Remove_database(p);
		return NULL;
	}
	if(fread(p->info, db.info_length, 1, fp)!=1)
	{
		fclose(fp);
		free(p->info);
		Remove_database(p);
		return NULL;
	}
	p->info[db.info_length]='\0';
	struct item_save temp;
	char *name;
	cahr *info;
	for(size_t i=1; i<=db.item_amount; i++)
	{
		if(fread(&temp, sizeof(struct item_save), 1, fp)!=1)
		{
			fclose(fp);
			Remove_database(p);
			return NULL;
		}
		if((name=(char *)malloc(temp.name_length+1))==NULL)
		{
			fclose(fp);
			for(size_t t=1; t<=i-1; t++)
				Delete_item(p, t);
			free(p->info);
			Remove_database(p);
			return NULL;
		}
		if(fread(&name, temp.name_length, 1, fp)!=1)
		{
			fclose(fp);
			free(name);
			Remove_database(p);
			return NULL;
		}
		name[temp.name_length]='\0';
		if((info=(char *)malloc(temp.info_length+1))==NULL)
		{
			fclose(fp);
			free(name);
			Remove_database(p);
			return NULL;
		}
		if(fread(&info, temp.info_length, 1, fp)!=1)
		{
			fclose(fp);
			free(name);
			free(info);
			Remove_database(p);
			return NULL;
		}
		info[temp.info_length]='\0';
		if(Add_item(p, name, temp.stored_amount, temp.saled_amount, temp.price, info)!=0)
		{
			fclose(fp);
			free(name);
			free(info);
			Remove_database(p);
			return NULL;
		}
		free(name);
		free(info);
	}
	fclose(fp);
	return p;
}

static struct item_save Convert_item_to_savemode(struct item store)
{
	struct item_save save=
	{
		store.stored_amount,
		store.saled_amount,
		store.price,
		strlen(store.name),
		strlen(store.info)
	};
	return save;
}

static struct database_save Convert_database_to_savemode(struct database origin)
{
	struct database_save save=
	{
		origin.item_amount,
		strlen(origin.info)
	}
	return save;
}
