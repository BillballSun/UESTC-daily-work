/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#include <stdio.h>
#include <stdbool.h>

#define LOOP for(;;)

struct item
{
	unsigned short num_code;
	double price;
	struct date
	{
		unsigned short year;
		unsigned char month, day;
	}purchase_date;
};

struct data
{
	size_t data_amount;
	struct item *item_array_point;
};

void Program_failed(void);
int Loading_data(const char *file_url, struct data *data_pointer);
void Display_data(struct data *data_pointer);

int main(int argc, char *argv[])
{
	if(argc!=2) Program_failed();
	struct data main_data;
	if(Loading_data(argv[1], &main_data)!=0) Program_failed();
	Display_data(&main_data);
	system("pause");
	return EXIT_SUCCESS;
}

void Program_failed(void)
{
	fprintf(stderr, "ERROR: program failed for illegal action.\n");
	system("pause");
	exit(EXIT_FAILURE);
}

/******************************************************
 *Loading_data
 *failed by opening file return -1
 *if nothing readed return 1
 *if allocate or realloc failed return 2
 *else successfully return 0
 ******************************************************/
int Loading_data(const char *file_url, struct data *data_pointer)
{
	data_pointer->data_amount=0u;
	data_pointer->item_array_point=NULL;
	FILE *fp;
	if((fp=fopen(file_url, "r"))==NULL) return -1;
	size_t item_count=0u, store_count=Initialized_allocation_num;
	if((data_pointer->item_array_point=malloc(sizeof(struct item)*Initialized_allocation_num))==NULL)
	{
		fclose(fp);
		return 2;
	}
	struct item temp_item;
	bool allocation_failed=false;
	LOOP /* Macro Difination */
	{
		if(Read_one_line(fp, &temp_item)!=0)
			break;
		if(item_count==store_count)
		{
			struct item *temp=realloc(data_pointer->item_array_pointer, store_count+Initialized_allocation_num);
			if(temp==NULL)
			{
				allocation_failed=true;
				break;
			}
			data_pointer->item_array_pointer=temp;
			store_count=store_count+Initialized_allocation_num;
		}
		data_pointer->item_array_pointer[store_count++]=temp_item;
	}
	fclose(fp);
	if(allocation_failed) return 2;
	else return 0;
}

int Read_one_line(FILE *fp, struct item *item_p)
{
	if (fscanf(fp, "%hu,%lf,%hhu/%hhu/%hu",
	    &item_p->num_code, &item_p->price, &item_p->purchase_date.month, &item_p->purchase_date.day, &item_p->purchase_date.year
	    <5) return -1;
	return 0;
}

/*
struct item
{
	unsigned short num_code;
	double price;
	struct date
	{
		unsigned short year;
		unsigned char month, day;
	}purchase_date;
};

struct data
{
	size_t data_amount;
	struct item *item_array_point;
};
*/

void Display_data(struct data *data_pointer)
{
	fprintf(stdout, "Item      Unit            Purchase\n");
	fprintf(stdout, "          Price           Date\n");
	struct item *temp;
	for(size_t i=1; i<=data_pointer->data_amount; i++)
	{
		temp=data_pointer->item_array_pointer+i-1;
		fprintf(stdout, "%-10hu$%7.2f        %hhu/%hhu/%hu\n",temp->num_code, temp->price,
		temp->purchase_date.month, temp->purchase_date.day, temp->purchase_date.year);
	}
}
