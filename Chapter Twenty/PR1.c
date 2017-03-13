//PR1
unsigned short i,j;
//(a)
i=8;j=9;
printf("%d",i>>1+j>>1);
i 0000000000001000
j 0000000000001001
//result is 0
//(b)
i=1;
printf("%d", i & ~i);
 i 0000000000000001
~i 1111111111111110
//result is 0
//(c)
i=2;
j=1;
k=0;
printf("%d", ~i & j ^ k);
-i 1111111111111101
 j 0000000000000001
 & 0000000000000001
 k 0000000000000000
 ^ 0000000000000001
//result is 1
//(d)
i=7;
j=8;
k=9;
printf("%d", i ^ j & k);
j 0000000000001000
k 0000000000001001
& 0000000000001000
i 0000000000000111
^ 0000000000001111
0x 000f
//result is 15
//PR2
//position range from 0 to max
//guess changing position is j
i ^= 1<<j;
//PR3
#define M(x,y)  ((x)^=(y), (y)^=(x), (x)^=(y))
//x0 y0			x0 y0
//x1 y0			x0 y1
//x0 y1			x1 y0
//x1 y1			x1 y1
//exchange two values without the third one
//xa ya			xa ya
//xa yb			xb ya
//PR4
typedef unsigned char Byte;

union color_type
{
	unsigned long main;
	struct
	{
		Byte red, green, blue;
	}source;
};
#define MK_COLOR(red, green, blue) (0x00000000u | ( (unsigned long)(red) | (unsigned long)(green)<<8 | (unsigned long)(blue)<<16 ))
//PR5
GET_RED(color) ((color)&(unsigned long)0x000000FFu)
GET_GREEN(color) (((color)>>8)&(unsigned long)0x000000FFu)
GET_BLUE(color) (((color)>>16)&(unsigned long)0x000000FFu)
//PR6
//(a)
unsigned short swap_bytes(unsigned short i)
{
	union
	{
		unsigned short word;
		struct
		{
			Byte first,second;
		}bytes;
	} result={i};
	result.bytes.first^=result.bytes.second;
	result.bytes.second^=result.bytes.first;
	result.bytes.first^=result.bytes.second;
	return result.word;
}
//(b)
#define Swap_bytes_for_unsigned_short(i) ((unsigned short)(0xFF00&(i)<<8|0x00FF&(i)>>8))
//PR7
unsigned int rotate_left_unsigned_int(unsigned int i, int n)
{
	int bits=sizeof(unsigned int)*8;
	n=n%bits;
	unsigned int pre_first=(i>>(bits-n))&(~(~0<<n));
	unsigned int pre_second=i&(~(~0<<(bits-n)));
	return pre_first|(pre_second<<n);
}

unsigned int rotate_right_unsigned_int(unsigned int i, int n)
{
	int bits=sizeof(unsigned int)*8;
	n=n%bits;
	unsigned int pre_first=(i>>n)&(~(~0<<(bits-n)));
	unsigned int pre_second=i&(~(~0<<n));
	return pre_first|pre_second<<(bits-n);
}
//PR8
unsigned int func(unsigned int i, int m, int n)
{
	return (i>>(m+1-n))&~(~0<<m);
}
//(a)
~(~0<<n) 0x000000FF (n==16) 0x00000001 (n==1)
//(b)
Get range from (m-n)position to (2m-n)positon digits
//INFO position range from 0 to max
//PR9
//(a)
int count_ones(unsigned char ch)
{
	int counts=0;
	for(size_t i=1; i<=(sizeof(unsigned char)*8);i++)
		if(1<<(i-1)&ch) counts++;
	return counts;
}
int count_ones(unsigned char ch)
{
	int counts;
	for(counts=0;ch>0;ch>>=1)
		if(ch&1) counts++;
	return counts;
}
int count_ones(unsigned char ch)
{
	int counts;
	int temp;
	while(ch>0)
	{
		temp=ch%2;
		if(temp>0) counts++;
		ch=ch/2;
	}
	return counts;
}
int count_ones(unsigned char ch)
{
	int counts;
	for(counts=0;ch!=0;ch&=ch-1)
		counts++;
	return counts;
}
//(b)
int count_ones(unsigned char ch)
{
	int counts=0;
	if(ch&1) counts++;
	if(ch&1<<1) counts++;
	if(ch&1<<2) counts++;
	if(ch&1<<3) counts++;
	if(ch&1<<4) counts++;
	if(ch&1<<5) counts++;
	if(ch&1<<6) counts++;
	if(ch&1<<7) counts++;
}
//PR10
unsigned int reverse_bits_unsigned_int(unsigned int n)
{
	unsigned int result=0;
	size_t bits=sizeof(unsigned int)*8;
	for(size_t i=1;i<=bits;i++)
		result|=(n>>(i-1)&1)<<(bits-i);
	return result;
}
//PR11
#define SHIFT_BIT 1
#define CTRL_BIT  2
#define ALT_BIT   4
if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
	printf("No modifier key matched\n");
//PR12
unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
	return (high_byte<<8)+low_byte;
}
//PR13
n &= n - 1;
clean all bits to zero (every time decrease just one 1 from the bottom)
//PR14
union float_view
{
	struct
	{
		unsigned int little_digits:23;
		unsigned int upper_digits:8;
		unsigned int fuhao:1;
	}float_digits;
	float float_all;
}
//PR15
struct
{
	int(signed/unsigned) flag:1;
}a;
a.flag=1;
printf("%d\n",s.flag);
1(unsigned)/-1(signed);
//PR16
typedef unsigned int Dword
typedef unsigned short Word
typedef unsigned char Byte

union
{
	struct
	{
		Dword EAX, EBX, ECX, EDX;
	}double_words;
	struct
	{
		Word AX, , BX, , CX, , DX, ;
	}word;
	struct
	{
		Byte a1, a2;
		Word;
		Byte b1, b2;
		Word;
		Byte c1, c2;
		Word;
		Byte d1, d2;
		Word;
	}byte;
}regs;
