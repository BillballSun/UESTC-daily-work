//PR1
void *my_malloc(size_t len)
{
	void *p=malloc(len);
	if(p==NULL)
	{
		printf("Allocation failed.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	return p;
}
//PR2
char *duplicate_string(const char * restrict source)
{
	char *p=(char *)malloc(strlen(source)+1);
	if(p==NULL) return NULL;
	while(*p++=*source++) continue;
	return p;
}
//PR3
int *create_array(size_t n, int initial_value)
{
	int *p=(int *)malloc(n);
	if(p==NULL) return NULL;
	for(size_t i=1;i<=n;i++)
		*(p+i-1)=initial_value;
	return p;
}
//PR4
struct point
{
	int x,y;
};
struct rectangle
{
	struct point upper_left, lower_right;
};
struct rectangle *p={.upper_left.x=10,.upper_left.y=25,.lower_right.x=20,lower_right.y=15};
//PR5
struct
{
	union
	{
		char a, b;
		int c;
	} d;
	int e[5];
}f, *p=&f;
//(a)
p->b=' ';		//wrong
//(b)
p->e[3]=10;		//legal
//(c)
(*p).d.a='*';	//legal
//(d)
p->d->c=20;		//wrong
//PR6
struct node
{
	int value;
	struct node *next;
};
void delete_from_list(struct node **list, int n)
{
	if((*list)->value==n)
	{
		struct node *temp=(*list)->next;
		free(*list);
		*list=temp;
		return;
	}
	struct node *pre;
	for(pre=*list;pre->next!=NULL;pre=pre->next)
		if(pre->next->value==n)
		{
			struct node *temp=pre->next->next;
			free(pre->next);
			pre->next=temp;
			return;
		}
}
//PR7
void release_link(struct node *begin)
{
	if(begin->next==NULL)
		free(begin);
	else
	{
		release_link(begin->next);
		free(begin);
	}
}
//PR8
struct content
{
	int value;
	struct content *next;
} *begin=NULL;
bool push(int value)
{
	struct content *new=(struct content *)malloc(sizeof(struct content));
	if(new==NULL) return false;
	
	if(begin==NULL)
		begin=new;
	else
	{
		struct content *last;
		for(last=begin;last->next!=NULL;last=last->next) continue;
		last->next=new;
	}
	return true;
}
//PR9
#define sun_rises_at_east true
struct node
{
	int a;
}x;
if((&x)->a==x.a) sun_rises_at_east;
//PR10
struct part
{
	int number;
	char name[Name_length+1];
	int on_hand;
};
void print_part(struct part *show)
{
	printf("Number: %d\n",show->number);
	printf("Name: %s\n",show->name);
	printf("Amount: %d\n",show->on_hand);
}
//PR11
int count_occurrences(struct node *begin, int n)
{
	int count=0;
	for(struct node *i=begin;i!=NULL;i=i->next)
		if(i->value==n) count++;
	return count;
}
//PR12
struct node *find_last(struct node *begin)
//if begin equals NULL return NULL
{
	if(begin==NULL) return NULL;
	struct node *last;
	for(last=begin;last->next!=NULL;last=last->next) continue;
	return last;
}
//PR13
struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
	struct node *cur=list, *prev=NULL;
	while(cur!=NULL&&cur->value<=new_node->value)
	{
		prev=cur;
		cur=cur->next;
	}
	if(prev==NULL)
	{
		new_node->next=list;
		list=new_node;
	}
	else
	{
		pre->next=new_node;
		new_node->next=cur;
	}
	return list;
}
//PR14
void delete_from_list(struct node **list, int n)
{
	if((*list)->value==n)
	{
		struct node *temp=(*list)->next;
		free(*list);
		*list=temp;
		return;
	}
	struct node *pre;
	for(pre=*list;pre->next!=NULL;pre=pre->next)
		if(pre->next->value==n)
		{
			struct node *temp=pre->next->next;
			free(pre->next);
			pre->next=temp;
			return;
		}
}
//PR15
#include <stdio.h>

int fl(int (*f)(int));
int f2(int i);

int main(void)
{
	printf("Answer: %d\n",f1(f2));
	return 0;
}

int f1(int (*f)(int))
{
	int n=0;
	while((*f)(n)) n++;
	return n;
}

int f2(int i)
{
	return i*i+i-12;
}
//Output Answer: 3
//Effect: n goes from 0 to 1,2,3,4... find the smallest to make (n*n+n)==12

//PR16
int sum(int (*f)(int), int start, int end)
{
	int result=0;
	for(int i=start;i<=end;i++)
		result=result+(*f)(i);
	return result;
}
//PR17
qsort(a+50-1, 50, sizeof(a[0]),...);
//PR18
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
struct part
{
	int number;
	char name[Name_length+1];
	int on_hand;
	struct part *next;
};
int new_compare(const void *left, const void *right)
{
	//return ((struct part *)right)->number-((struct part *)left)->number;
	//perhaps overflow by int
	if(((struct part *)right)->number==((struct part *)left)->number)
		return 0;
	if(((struct part *)right)->number>((struct part *)left)->number)
		return 1;
	else
		return -1;
}
//PR19
#define Command_amount 9
struct
{
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[Command_amount]=
{
	{"new",				new_cmd},
	{"open",			open_cmd},
	{"close",			close_cmd},
	{"close all",		close_all_cmd},
	{"save",			save_cmd},
	{"asve as",			save_as_cmd},
	{"save all",		save_all_cmd},
	{"print",			print_cmd},
	{"exit",			exit_cmd}
};

void Call_cmd(char *cmd)
{
	for(int i=i;i<=Command_amount;i++)
		if(strcmp(file_cmd[i-1].cmd_name,cmd)==0)
			(*file_cmd[i-1].cmd_pointer)();
}
