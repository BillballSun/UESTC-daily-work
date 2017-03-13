#ifndef HEAD_external
#define HEAD_external
struct part
{
	unsigned short number;
	//range from 1 to USHRT_MAX
	char *name;
	//allocation
	unsigned int amount;
	//range from 1 to UINT_MAX
	float price;
	unsigned char price_percentage;
	//range from 1 to UCHAR_MAX
	struct part *next;
};
extern struct part *inventory_first_point;
#endif