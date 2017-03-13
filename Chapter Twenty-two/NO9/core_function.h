#ifndef HEAD_core_function
#define HEAD_core_function

void Show_present_procedure(void);
void Load_database_procedure(void);
void Output_databse_procedure(void);
void Creating_database_procedure(void);
void Search_database_procedure(void);
void Print_database_procedure(void);
void Divide_line(void);
void Clean_stdin(void);
void Add_item_procedure(void);
void Delete_item_procedure(void);
char Get_a_lower_range(char *main_info, char *enter_info, char *range);
void Sale_item_procedure(void);
void Change_info_procedure(void);
void Combining_files_procedure(void);

/*Triger 0 or 1*/
#define Sale_could_more_than_store 1

#define Info_display_length 18u /* unsigned int wish no more than 255 */

#define Decent_match_percentage 90 /* percetage range 1-100 */

#endif