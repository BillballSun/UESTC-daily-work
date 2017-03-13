#ifndef HEAD_databaseADT
#define HEAD_databaseADT

#define Item_name_length 64
#define Info_length USHRT_MAX

/* Check_database */
#define Check_repair 1
#define Check_result 2

/* Get_item_date */
#define GET_item_date_input 1
#define GET_item_date_modify 2

typedef struct database *Data;

/******************************************************
 *Loading database steps
 *database->info->item->info
 *if open and load failed return NULL
 *After reading data fclose automatically
 ******************************************************/
Data Loading_database(char *url);

/******************************************************
 *Saving data to file
 *if it failed due to open/create it or writing error
 *return EOF else return zero and clean the file
 *If url equals NULL try to use url in the database
 ******************************************************/
int Saving_database(Data database, char *url);

/******************************************************
 *Generate a new database, if failed return NULL
 *else return pointer to the new_database
 ******************************************************/
Data Generate_database(void);

/******************************************************
 *Just destory a database, do not give NULL
 ******************************************************/
void Destroy_database(Data database);

/******************************************************
 *If it failed the return EOF
 *else return zero
 ******************************************************/
int Adding_item(Data database, char *name, unsigned long amount, double price);

size_t Get_item_ID(Data database, char *name);

Data Combine_two_file(char *url_1, char *url_2);

/******************************************************
 *If amount>stored then clean all stored and all amount
 *to the saled_amount
 ******************************************************/
unsigned long Sale_product_by_ID(Data database, size_t ID, unsigned long amount);

int Adding_info_to_database(Data database, char *info);

int Adding_info_to_item(Data database, size_t ID, char *info);

char *Get_database_info(Data database);

char *Get_item_info(Data database, size_t ID);

size_t Get_database_amount(Data database);

char *ALLOCATE_database_create_date(Data database);

char *ALLOCATE_item_input_date(Data database, size_t ID);

char *ALLOCATE_item_modify_date(Data database, size_t ID);

char *Get_item_name(Data database, size_t ID);

unsigned long Get_item_store_amount(Data database, size_t ID);

unsigned long Get_item_saled_amount(Data database, size_t ID);

double Get_item_price(Data database, size_t ID);

/******************************************************
 *Get_item_date
 *if error happens return EOF else return zero
 *if one date_object is not needed, just type NULL is OK!
 ******************************************************/
int Get_item_date(Data database, size_t ID, int mode, int *year, int *month, int *day, int *hour, int *min, int *sec);

int Check_database(Data database, int mode);

int Destory_item(Data database, size_t ID);
#endif
