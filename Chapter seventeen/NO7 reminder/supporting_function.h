#ifndef HEAD_supporting_function
#define HEAD_supporting_function
bool Is_number(char);
int Get_a_day(char *);
unsigned int Get_a_id(void);
bool Get_Y_or_N(char *);
char Get_a_upper_letter(void);
void Show_id_detailed_info(unsigned int);
bool Safe_read_name(char *, int);
char *Read_message(unsigned int);
void Free_event_by_ID(int);
void Clean_stored_id(unsigned int *, unsigned int);
int Get_some_days_selected(bool *);
bool Decent_match(char *, char *);
char Get_a_range(char, char,char *,char *);
#endif