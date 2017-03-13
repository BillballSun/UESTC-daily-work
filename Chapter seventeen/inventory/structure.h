#ifndef HEAD_structure
#define HEAD_structure
#include <stdbool.h>
bool Get_Y_or_N(char *info);
char Get_a_upper_letter(void);
char Get_a_upper_range(char begin, char end ,char *option ,char *message);
void Get_rid_of_RestLine(void);
void Print_small_line(void);
void Print_divide_line(void);
#endif