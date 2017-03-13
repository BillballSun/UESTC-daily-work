#ifndef HEAD_external
#define HEAD_external
struct event
{
	unsigned char day; //0-255
	char *message;
};
extern struct event reminder[];
extern unsigned int present_event_amount;
#endif
