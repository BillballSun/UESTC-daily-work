//PR1
struct { int x, y; }x;
struct { int x, y; }y;
//Could exist together
//PR2
struct c_type
{
	double real,imaginary;
} c1={0.0,1.0},c2={1.0,0.0},c3;
c1=c2;
c3.real=c1.real+c2.real;
c3.imaginary=c2.imaginary+c3.imaginary;
#define c_type_sum(total,part1,part2) \
do \
{ \
total#.real=part1#.real+part2#.real; \
total#.imaginary=part1#.imaginary+part2#.imaginary; \
}while(0)
c_type_sum(c3,c1,c2);
//PR3
struct complex
{
	double real,imaginary;
};
struct complex c1,c2,c3;
//C99
struct complex make_complex(double real, double imaginary)
{
	return (struct complex){.real=real,.imaginary=imaginary};
}
//C++
struct complex make_complex(double real, double imaginary)
{
	struct complex result={real,imaginary};
	return result;
}
//PR4 the authur's head has problems. Please call ambulance immediately.
//PR5
struct date
{
	int year,month,day;
};

bool Is_leap_year(int year)
{
	if(year%100==0)
		if(year%400==0) return true;
		else return false;
	else
		if(year%4==0) return true;
		else return false;
}

int day_of_year(struct date date)
{
	unsigned char day_every_month[12]
	{31,28,31,30,31,30,31,31,30,31,30,31};
	if(Is_leap_year(date.year)) *(day_every_month+1)+=1;
	int result=0;
	for(int i=1;i<date.month;i++)
		result=result+day_every_month[i-1];
	result=result+date.day;
	return result;
}

int compare(struct date date1, struct date date2)
//return day(date1)-day(date2)
{
	unsigned char day_every_month[12]
	{31,28,31,30,31,30,31,31,30,31,30,31};
	bool negative=false;
	if(date1.year<date2.year) negative=true;
	else if(date1.year==date2.year)
		if(date1.month<date2.month) negative=true;
		else if(date1.month==date2.month)
			if(date1.day<date2.day) negative=true;
	if(negative)
	{
		struct date temp;
		temp=date1;
		date1=date2;
		date2=temp;
	}
	int day_sum=0;
	if(date2.year<date1.year)
	{
		if(Is_leap_year(date2.year)&&date2.month<=2) day_sum=day_sum+1;
		day_sum=day_every_month[date2.month-1]-date2.day;
		for(int i=date2.month+1;i<=12;i++)
			day_sum=day_sum+day_every_month[i-1];
		for(int i=date2.year+1;i<date1.year;i++)
			day_sum+=Is_leap_year(i)?366:365;
		if(date1.month>2) day_sum+=1;
		for(int i=1;i<date1.month;i++)
			day_sum+=day_every_month[i-1];
		day_sum+=date1.day;
	}
	else
		if(date1.month==date2.month) day_sum=date1.day-date2.day;
		else
		{
			if(Is_leap_year(date2.year)&&date2.month==2) day_sum+=1;
			day_sum+=day_every_month[date2.month-1]-date2.day;
			if((date.month+1<=2)&&(date1.month-1>=2)) day_sum+=1;
			for(int i=date2.month+1;i<date1.month;i++)
				day_sum+=day_every_month[i-1];
			day_sum+=date2.day;
		}
	if(negative) day_sum=-day_sum;
	return day_sum;
}
//PR6
#define seconds_every_day 86400
#define seconds_every_hour 3600
#define seconds_every_minute 60
struct time_board
{
	signed char hour,minute,second;
};

struct time_board split_time(long total_seconds)
{
	signed char hour,minute,second;
	total_seconds%=seconds_every_day;
	hour=total_seconds/seconds_every_hour;
	total_seconds%=seconds_every_hour;
	minute=total_seconds/seconds_every_minute;
	total_seconds%=seconds_every_minute;
	second=total_seconds;
	struct time_board result
	={hour,minute,second};
	return result;
}
//PR7
struct fraction
{
	int numerator,demoninator;
};

struct fraction *function_a(struct fraction * const pointer)
{
	int up=(*pointer).numerator;
	  down=(*pointer).demoninator;
	bool negative=false;
	if(up<0) {negative=!negative;up=-up;}
	if(down<0) {negative=!negative;down=-down;}
	if(up==0) down=1;
	else
	{
		int a=up,b=down,temp;
		if(a<b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		while(b)
		{
			temp=a%b;
			a=b;
			b=temp;
		}
		up=up%a;
		down=down%a;
	}
	(*pointer).numerator=up;
	(*pointer).demoninator=down;
	return pointer;
}

struct fraction function_b(const struct fraction fraction1, const struct fraction fraction2)
{
	struct fraction result;
	result.numerator=fraction1.numerator*fraction2.demoninator+fraction2.numerator*fraction1.demoninator;
	result.demoninator=fraction1.demoninator*fraction2.demoninator;
	return result;
}

struct fraction function_b(const struct fraction fraction1, const struct fraction fraction2)
{
	struct fraction result;
	result.numerator=fraction1.numerator*fraction2.demoninator-fraction2.numerator*fraction1.demoninator;
	result.demoninator=fraction1.demoninator*fraction2.demoninator;
	return result;
}

struct fraction function_c(const struct fraction fraction1, const struct fraction fraction2)
{
	struct fraction result;
	result.numerator=fraction1.numerator*fraction2.numerator;
	result.demoninator=fraction1.demoninator*fraction2.demoninator;
	return result;
}

struct fraction function_c(const struct fraction fraction1, const struct fraction fraction2)
{
	struct fraction result;
	result.numerator=fraction1.numerator*fraction2.demoninator;
	result.demoninator=fraction1.demoninator*fraction2.numerator;
	return result;
}
//PR8
struct color
{
	unsigned char red,green,blue;
};
//C98
const struct color Magenta={255,0,255};
//C99
const struct color Magenta={.red=255,.blue=255};
//PR9
unsigned char Color_limit(double input)
{
	if(input>255) return 255;
	if(input<0)   return 0;
	return (unsigned char)input;
}

struct color Make_color(int red, int green, int blue)
{
	struct color result={Color_limit(red),Color_limit(green),Color_limit(blue)};
	return result;
}

//C99
struct color Make_color(int red, int green, int blue)
{
	return (struct color){.red=Color_limit(red),.green=Color_limit(green),.blue=Color_limit(blue)};
}

unsigned char GetRed(struct color input)
{
	return input.red;
}

bool Equal_color(const struct color color1, const struct color color2)
{
	if(color1.red!=color2.red) return false;
	if(color1.green!=color2.green) return false;
	if(color1.blue!=color2.blue) return false;
	return true;
}

struct color Brighter(struct color c)
{
	struct color result;
	if(c.red==0&&c.red==c.green&&c.red==c.blue)
	{
		c.red=3;
		c.green=3;
		c.blue=3;
	}
	else
	{
		if(c.red>0&&c.red<3) c.red=3;
		if(c.green>0&&c.green<3) c.green=3;
		if(c.blue>0&&c.blue<3) c.blue=3;
		
		c.red=Color_limit((double)c.red/0.7);
		c.green=Color_limit((double)c.green/0.7);
		c.blue=Color_limit((double)c.blue/0.7);
	}
	result.red=c.red;
	result.green=c.green;
	result.blue=c.blue;
	return result;
}

struct color Darken(struct color c)
{
	struct color result;
	result.red=c.red*0.7;
	result.green=c.green*0.7;
	result.blue=c.blue*0.7;
	return result;
}
//PR10
struct point
{
	int x,y;
};

struct rectangle
{
	struct point upper_left, lower_right;
}

int GetArea(struct rectangle r)
{
	return (r.lower_right.x-r.upper_left.x)*(r.lower_right.y-r.upper_left.y);
}

struct point GetCenter(struct rectangle r)
{
	struct point center;
	center.x=(r.lower_right.x+r.upper_left.x)/2;
	center.y=(r.lower_right.y+r.upper_left.y)/2;
	return center;
}

struct rectangle MoveSqaure(struct rectangle r,int move_x,int move_y)
{
	r.upper_left.x+=move_x;
	r.upper_left.y+=move_y;
	r.lower_right.x+=move_x;
	r.lower_right.y+=move_y;
	return r;
}

bool Is_inside(struct rectangle r, struct point p)
{
	if(p.x>=r.upper_left.x&&p.x<=r.lower_right.x&&p.y>=r.upper_left.y&&p.y<=r.lower_right.y) return true;
	else return false;
}
//PR11
struct
{
	double a;
	union
	{
		char b[4];
		double c;
		int d;
	}e;
	char f[4];
}s;
//for x32 and x64
//sizeof(s)=15(double a)+15(union e double c)+4(char f[4])=34
//PR12
union
{
	double a;
	struct
	{
		char b[4];
		double c;
		int d;
	}e;
	char f[4];
}s;
//sizeof(s)=15
//PR13
#define Rectangle 0
#define Circle 1
#define Pi 3.141596

struct point
{
	int x,y;
};

struct shape
{
	int shape_kind;
	struct point center;
	union
	{
		struct
		{
			int height,width;
		}rectangle;
		struct
		{
			int radius;
		}circle;
	}u;
}s;

s.shape_kind=Rectangle;
s.center.x=10;
s.height=25; /*illegal*/
s.u.rectangle.width=8;
s.u.circle=5; /*illegal*/
s.u.radius=5; /*illegal*/
//PR14
double GetArea(const struct shape chape1)
{
	double result;
	if(shape1.shape_kind==Rectangle)
		result=shape1.u.rectangle.height*shape1.u.rectangle.width;
	else
		result=shape1.u.circle.radius*shape1.u.circle.radius*Pi;
	return result;
}

struct shape Move(struct shape shape1, int x_move, int y_move)
{
	shape1.point.x+=x_move;
	shape1.point.y+=y_move;
	return shape1;
}

struct shape Zoom(struct shape shape1, double zoom_scale)
{
	if(shape1.shape_kind==Rectangle)
	{
		shape1.u.rectangle.height*=zoom_scale;
		shape1.u.rectangle.width*=zoom_scale;
	}
	else
		shape1.u.circle.radius*=zoom_scale;
	return shape1;
}
//PR15
typedef enum week
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
} Week_type;
//PR18
enum color
{
	Black,
	White
};

enum chest
{
	Empty,
	Soldier,
	House,
	Elephant,
	Car,
	Queen,
	King
};

struct content
{
	enum color color;
	enum chest content;
};

struct content board[8][8]=
{
	[1][1].content=King,[1][1].color=White
	//...
};
//PR19
#define Max_name_length 40

enum machine_type
{
	EM,
	SS
};

struct pinball_machine
{
	char name[Max_name_length+1];
	unsigned short year;
	enum machine_type type;
	unsigned int players;
};

enum direction
{
	North,
	South,
	East,
	West
};

void Redirection(enum direction direct, int *x,int *y)
{
	switch(direct)
	{
		case North:*y+=1;break;
		case South:*y-=1;break;
		case East:*x+=1;break;
		case West:*x-=1;break;
	}
}
//PR21
enum {NUL, SOH, STX, ETX};
//0 1 2 3
enum {VT=11, FF, CR};
//11 12 13
enum {SO=14, SI, DLE, CAN=24, EM};
//14 15 16 24 25
enum {ENQ=45, ACK, BEL, LF=37, ETB, ESC};
//45 46 47 37 38 39
//PR22
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
int piece_value[PAWN+1]={200, 9, 5, 3, 3, 1};
//C99
int piece_value[]={[KING]=200, [QUEEN]=9, [ROOK]=5, [BISHOP]=3, [KNIGHT]=3, [PAWN]=1};
