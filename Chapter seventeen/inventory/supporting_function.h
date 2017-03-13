#ifndef HEAD_supporting_function
#define HEAD_supporting_function
unsigned short Get_a_number(void);
unsigned int Get_an_order(void);
char* Get_a_name(void);
unsigned int Get_an_amount(void);
float Get_a_price(void);
unsigned char Get_price_percentage(void);
struct part *Get_a_part(void); //Useless
struct part *Locate_a_part_by_number(unsigned short number);
void Insert_a_part(struct part *new_part);
bool Decent_match(char *s1, char *s2);
void Show_part_by_point(struct part *previous_part);
void Remove_a_part(struct part *previous_part);
void Modify_part_by_point(struct part *modify_part);
unsigned int Get_amount_change(unsigned int former_amount);
void Find_parts(struct part ***link_point, size_t *amount);
#endif