#ifndef HEAD_structure_support
#define HEAD_structure_support
#include <stdbool.h>
void Print_divide_line(void);
void Print_small_line(void);
void Get_rid_of_RestLine(void);
bool Safe_read_name(char *string_for_storage,int length); /* length like sizeof(char *)-1 */
char Get_a_upper_range(char *main_massage, char *input_show, char *range);
#endif
