/********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By Bill Sun                                           *
* Copyright (c) 2016, 1998 CaptainAllred Incorperated.  *
* All rights reserved.                                  *
* This program may not be freely distributed,           *
* provided that this copyright notice is retained.      *
********************************************************/

#ifndef HEAD_databaseADT
#define HEAD_databaseADT

/* Search function mode */
#define Search_mode_name			0x01
#define Search_mode_store_amount	0x02
#define Search_mode_saled_amount	0x04
#define Search_mode_price			0x08
#define Search_mode_info			0x10

/* Url test result */
#define File_already_exist 1
#define File_canbe_created 0
#define File_access_denied -1

#define Info_for_item_header \
"     ID           Name       Stored      Saled      Price   Info\n" \
"----------------------------------------------------------------\n"

typedef struct database *Database;

char *Allocate_info_for_an_item(const Database p, size_t ID);
size_t Search_item(const Database p, size_t count, char *name, size_t stored_amount, size_t saled_amount, double price, char *info, unsigned char search_mode);
int Delete_item(Database p, size_t ID);
struct item *Locate_item(const Database p, size_t ID);
int Add_item(Database p, char *name, size_t stored_amount, size_t saled_amount, double price, char *info);
int Test_database(const Database p);
Database *Generate_database(char *info);
size_t Get_database_item_amount(const Database p);
char *Get_database_info(const Database p);
size_t Get_database_item_amount(const Database p);
char *Get_database_info(const Database p);
char *Get_item_name(const Database p, size_t ID);
size_t Get_item_stored_amount(const Database p, size_t ID);
size_t Get_item_saled_amount(const Database p, size_t ID);
char *Get_item_info(const Database p, size_t ID);
void Remove_database(Database *p);
int Save_database(Database p, char *url);
Database *Load_database(char *url);
int Is_url_accepted(char *url);

#endif