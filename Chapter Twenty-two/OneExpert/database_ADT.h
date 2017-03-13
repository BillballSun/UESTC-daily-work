#ifndef HEAD_database_ADT
#define HEAD_database_ADT
#include <stdbool.h>
#define Max_event_amount 7u /*unsigned int 7-36*/
#define Max_subject_name_length 64 /*unsigned char 16-255*/
#define Expert_time 10000ul /*unsigned long default one milion hours*/
#define Default_storage_url "C:/Users/Bill Sun/Documents/OneExpert/"

/******************************************************
 *begin function for OneExpert
 *Is_data_exit will try to find the database via url
 *If file access failed EXIT program
 *If data missing create EMPTY data return 0
 *If load data failed then create empty data return -1
 *If open and load successfully return 1
 ******************************************************/
int Is_data_exist(void);

/******************************************************
 *AFTER CALL Is_data_exit
 *Create_a_new_subject will create a new subject
 *Input: string is the name of the subject
 *if Max_event_amount in the database reached
 *nothing happened
 *if reallocation/first alloaction failed nothing happened
 ******************************************************/
void Create_new_suject(const char *input_your_subject_name_string);

/******************************************************
 *Save_data
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Save_data(void);

/******************************************************
 *Change the name in the settings
 *AFTER CALL Is_data_exit
 *Program will support at least 12 digits length
 ******************************************************/
void Change_user_name(const char *first_name_string, const char *second_last_string);

/******************************************************
 *Show detailed info for one subject via its ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened
 ******************************************************/
void Show_subject_info(unsigned int ID);

/******************************************************
 *Show_database_info
 *AFTER CALL Is_data_exit
 *print detailed info for the whole database
 ******************************************************/
void Show_database_info(void);

/******************************************************
 *Add_subject_time will increase one subject time via ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened and return false as default
 *If I mean if he becomes an expert then return true else return false
 ******************************************************/
bool Add_subject_time(unsigned int ID, unsigned long learning_hours, unsigned int learning_minutes);

/******************************************************
 *Show_status_brand for one subject via its ID
 *AFTER CALL Is_data_exit
 *if it not exists nothing happened
 ******************************************************/
void Show_status_brand(unsigned int ID);

/******************************************************
 *Show_subject_still_need will print the time needed for an expert via ID
 *AFTER CALL Is_data_exit
 *if he already an expert return FALSE and do nothing
 *else print some info and return true as default
 ******************************************************/
bool Show_subject_still_need(unsigned int ID);

/******************************************************
 *Get_present_ID_range returns present_amount of subjects
 *AFTER CALL Is_data_exit
 ******************************************************/
unsigned int Get_present_ID_range(void);

/******************************************************
 *Is_database_full return you know
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Is_database_full(void);

/******************************************************
 *AFTER CALL Is_data_exit
 ******************************************************/
bool Is_user_name_set(void);
#endif
