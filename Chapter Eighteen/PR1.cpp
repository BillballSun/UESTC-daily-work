//PR8 and PR9
//(a)
char (*x[10])(int);
//array[10] of pointer of function(inputing int) returning char
typedef char func(int);
typedef func *p;
typedef p array[10];
array x;
//(b)
int (*x(int))[5];
//function(inputing int) returning pointer of array[5] of int
typedef int array[5];
typedef	array *p;
typedef p func(int);
func x;
//(c)
float *(*x(void))(int);
//function (inputing void) returning pointer of function (inputing int) returning pointer of float;
typedef float *p_f;
typedef p_f func1(int);
typedef func1 *p;
typedef p func2(void);
func2 x;
//(d)
void (*x(int, void(*y)(int)))(int);
//function (inputing int and (pointer of function (inputing int) returning void)) returning pointer of function (inputing int) returning void
typedef void func1(int);
typedef func1 *p_1;
#
typedef void func2(int);
typedef func2 *p_2;
#
typedef p_1 func3(int, p_2);
func3 x;
//PR10
//(a)
char *(*p)(char *);
//(b)
void (*)(void) f(struct t *p, long n);
//(c)
void (*a[4])(void)={insert, search, update, print};
//(d)
struct t (*b[10])(int, int);
//Personal preferance
struct t
{
	(double)(*)(short)(*pointer)(**char, void (*)(float, long));
	union
	{
		float a,b;
		char ch[10];
	}u(long long);
	struct t *next;
} (*x(int, void(*)(int)))(long[],(char)(*)(unsigned long long, float));
//PR11
int (*f(int))[];
int (*g(int))(int);
int (*a[10])(int);
//PR12
//(a)
int (*f(float (*)(long), char *))(double);
//function (inputing (pointer of function (inputing long) returning float) and pointer of char) returning pointer function (inputing double) returning int
//(b)
//The author's head went wrong...
#define String_length 10
float My_function(long);
char string[String_length+1];
int (*pointer)(double)=f(My_function, string);
//PR13
#define PI 3.14159f
//(a)
char c=65;//legal
//(b)
static int i=5, j=i*i;//legal
//(c)
double d=2*PI;//legal
//(d)
double angles[]={0, PI/2, PI, 3*PI/2};//legal
//PR14
Intialization for array, enumeration, structure, union is acceptable;
//INFO union is acceptable
//PR15
A
