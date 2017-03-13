#define _CRT_SECURE_NO_DEPRECATE /* Before all the includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "database_ADT.h"
#if 0
	#define Max_event_amount 7u /*unsigned int 7-36*/
	#define Max_subject_name_length 64 /*unsigned char 16-255*/
	#define Expert_time 100000ul /*unsigned long default one milion hours*/
	#define Default_storage_url "C:/Users/Bill Sun/Documents/OneExpert/"
#endif

#include "database_ADT_client_check.h"
#if 0
	#define STD_vison 1
	#if Max_event_amount<7||Max_event_amount>36
		#error Event_amount_flows
	#elif Max_event_amount!=7
		#undef STD_vison
		#define STD_vison 0
	#endif
	#if Max_subject_name_length<16||Max_subject_name_length>255
		#error Subject name flows
	#elif
		#undef STD_vison
		#define STD_vison 0
	#endif
	#if Expert_time!=100000ul
		#undef STD_vison
		#define STD_vison 0
		#if Expert_time<100
			#error It is too short to become an expert_time
		#elif Expert_time>1000000ul
			#error It is too long to accomplish in life time
		#endif
	#endif
#endif

/*default settings for data*/
#define User_setting_name_length 12
#define Vison_main 1 /*unsigned char*/
#define Vison_modify 0 /*unsigned char*/
#define Vison_test 0 /*unsigned char*/
/*end of default settings for data*/

typedef unsigned char byte;

static struct whole_info
{
	unsigned int array_length;
	unsigned int present_amount;
	unsigned long expert_time;
	byte subject_name_length;
	struct subject_data *subject_array;
}database;

static struct subject_data
{
	char name[Max_subject_name_length+1];
	unsigned long timer_hour;
	byte timer_minute;
};

static struct setting
{
	byte vision_main;
	byte vision_modify;
	byte vision_test;
	bool name_set;
	char user_first_name[User_setting_name_length+1];
	char user_last_name[User_setting_name_length+1];
}settings;

static void Empty_all_data(void);
static bool Load_data(void);

FILE *database_fp=NULL;

/******************************************************
 *begin function for OneExpert
 *Is_data_exit will try to find the database via url
 *If file access failed EXIT program
 *If data missing create EMPTY data return 0
 *If load data failed then create empty data return -1
 *If open and load successfully return 1
 ******************************************************/
int Is_data_exist(void)
{
	if((database_fp=fopen(Default_storage_url"database.dat", "rb+"))==NULL)
	{
		if((database_fp=fopen(Default_storage_url"database.dat", "wb+"))==NULL)
		{
			fprintf(stderr, "Error, file acception denied.\n");
			system("pause");
			exit(EXIT_FAILURE);
		}
		Empty_all_data();
		return 0;
	}
	if(Load_data()==false)
	{
		Empty_all_data();
		return -1;
	}
	return 1;
}

static void Empty_all_data(void)
{
	database.array_length=Max_event_amount;
	database.present_amount=0u;
	database.expert_time=Expert_time;
	database.subject_name_length=Max_subject_name_length;
	database.subject_array=NULL;
	settings.vision_main=Vison_main;
	settings.vision_modify=Vison_modify;
	settings.vision_test=Vison_test;
	settings.name_set=false;
	*(settings.user_first_name)='\0';
	*(settings.user_last_name)='\0';
}

/******************************************************
 *AFTER CALL Is_data_exit
 *Create_a_new_subject will create a new subject
 *Input: string is the name of the subject
 *if Max_event_amount in the database reached
 *nothing happened
 *if reallocation/first alloaction failed nothing happened
 ******************************************************/
void Create_new_suject(const char *string)
{
	if(database.present_amount==database.array_length) return;
	struct subject_data *temp;
	if(database.subject_array!=NULL)
		temp=(struct subject_data *)realloc(database.subject_array, (database.present_amount+1)*sizeof(struct subject_data));
	else
		temp=(struct subject_data *)malloc(sizeof(struct subject_data));
	if(temp==NULL) return;
	strncpy((temp+database.present_amount)->name, string, User_setting_name_length);
	(temp+database.present_amount)->name[User_setting_name_length]='\0';
	(temp+database.present_amount)->timer_hour=0ul;
	(temp+database.present_amount)->timer_minute=0u;
	database.subject_array = temp;
	database.present_amount++;
}

static bool Load_data(void)
{
	rewind(database_fp);
	if(fread(&settings, sizeof(struct setting), 1, database_fp)==0) return false;
	if(fread(&database, sizeof(struct whole_info), 1, database_fp)==0) return false;
	if(database.present_amount==0) database.subject_array=NULL;
	else
	{
		struct subject_data *temp;
		temp=(struct subject_data *)malloc(sizeof(struct subject_data)*database.present_amount);
		if (temp == NULL) return false;/*No need to clean database.subject_array=NULL*/
		if(fread(temp, sizeof(struct subject_data)*database.present_amount, 1, database_fp)==0)
		{
			free(temp);
			return false;
		}
		database.subject_array = temp;
	}
	return true;
}

/******************************************************
 *Save_data
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Save_data(void)
{
	rewind(database_fp);
	fwrite(&settings, sizeof(struct setting), 1, database_fp);
	fwrite(&database, sizeof(struct whole_info), 1, database_fp);
	fwrite(database.subject_array, sizeof(struct subject_data), database.present_amount, database_fp);
	if(ferror(database_fp)) return false;
	fflush(database_fp);
	return true;
}

/******************************************************
 *Change the name in the settings
 *AFTER CALL Is_data_exit
 *Program will support at least 12 digits length
 ******************************************************/
void Change_user_name(const char *first, const char *last)
{
	settings.name_set=true;
	strncpy(settings.user_first_name, first, User_setting_name_length);
	settings.user_first_name[User_setting_name_length]='\0';
	strncpy(settings.user_last_name, last, User_setting_name_length);
	settings.user_first_name[User_setting_name_length]='\0';
}

/******************************************************
 *Show_database_info
 *AFTER CALL Is_data_exit
 *print detailed info for the whole database
 ******************************************************/
void Show_database_info(void)
{
	printf("------------Database info------------\n");
	printf("Vision %hhd.%hhd.%hhd\n", settings.vision_main, settings.vision_modify, settings.vision_test);
	if(settings.name_set) printf("Belong to %s, %s\n", settings.user_first_name, settings.user_last_name);
	else printf("Belong to a person with non-name.\n");
	printf("-------------------------------------\n");
	printf("Subject limit:%u\n", database.array_length);
	printf("Subject present amount:%u\n", database.present_amount);
	printf("Default expert time: %lu\n", database.expert_time);
	if(database.present_amount==0)
		printf("Database haven\'t get any subjects.\n");
	else
		for(unsigned int i=1; i<=database.present_amount; i++)
		{
			printf("======================\n");
			Show_subject_info(i);
		}
}

/******************************************************
 *Show detailed info for one subject via its ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened
 ******************************************************/
void Show_subject_info(unsigned int ID)
{
	if(ID>database.present_amount||ID<1||database.present_amount==0) return;
	struct subject_data *temp=database.subject_array+ID-1;
	printf("Subject %s\n", temp->name);
	printf("ID: %u\n",ID);
	Show_status_brand(ID);
	printf("learning for %lu hours and %hhd minutes\n", temp->timer_hour, temp->timer_minute);
}


/******************************************************
 *Show_status_brand for one subject via its ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened
 ******************************************************/
void Show_status_brand(unsigned int ID)
{
	if(ID>database.present_amount||ID<1||database.present_amount==0) return;
	struct subject_data *temp=database.subject_array+ID-1;
	printf("Status: ");
	if(temp->timer_hour<=(database.expert_time/1000000)) printf("frozen-standing confuser");
	else if(temp->timer_hour<=(database.expert_time/100000)) printf("lovely looker");
	else if(temp->timer_hour<=(database.expert_time/50000)) printf("little interested beginner");
	else if(temp->timer_hour<=(database.expert_time/10000)) printf("Got useder");
	else if(temp->timer_hour<=(database.expert_time/1000)) printf("Wonderinger");
	else if(temp->timer_hour<=(database.expert_time/100)) printf("Familiareder");
	else if(temp->timer_hour<=(database.expert_time/10)) printf("Devoteder");
	else if(temp->timer_hour<database.expert_time) printf("Good Kowner");
	else if(temp->timer_hour>=database.expert_time) printf("Great Master");
	putchar('\n');
}

/******************************************************
 *Add_subject_time will increase one subject time via ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened and return false as default
 *If I mean if he becomes an expert then return true else return false
 ******************************************************/
bool Add_subject_time(unsigned int ID, unsigned long hours, unsigned int minutes)
{
	if(ID>database.present_amount||ID<1||database.present_amount==0) return false;
	struct subject_data *temp=database.subject_array+ID-1;
	temp->timer_hour+=hours;
	unsigned long minutes_temp=temp->timer_minute+minutes;
	temp->timer_hour+=minutes_temp/60;
	minutes_temp=minutes_temp%60;
	temp->timer_minute=minutes_temp;
	if(temp->timer_hour>=database.expert_time) return true;
	else return false;
}

/******************************************************
 *Show_subject_still_need will print the time needed for an expert via ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened and return false as default
 *if he already an expert return FALSE and do nothing
 *else print some info and return true as default
 ******************************************************/
bool Show_subject_still_need(unsigned int ID)
{
	if(ID>database.present_amount||ID<1||database.present_amount==0) return false;
	struct subject_data *temp=database.subject_array+ID-1;
	if(temp->timer_hour>=database.expert_time) return false;
	const double ratio_full_to_expect=356/(double)(365-30*3);
	/*This ratio consider one year with 3months rest*/
	unsigned long time_need=database.expert_time-temp->timer_hour;
	unsigned long days_need;
	printf("You have %lu hours for reaching the expert lever.\n", time_need);
	days_need=time_need/8*ratio_full_to_expect;
	printf("If you study about 8 hours one day,\nthen you need %lu years, %lu months and %lu days.\n",
	days_need/365, (days_need%365)/31, days_need%31);
}

/******************************************************
 *Get_present_ID_range returns present_amount of subjects
 *AFTER CALL Is_data_exit
 ******************************************************/
unsigned int Get_present_ID_range(void)
{
	return database.present_amount;
}

/******************************************************
 *Is_database_full return you know
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Is_database_full(void)
{
	return database.present_amount == database.array_length;
}

/******************************************************
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Is_user_name_set(void)
{
	return settings.name_set;
}
