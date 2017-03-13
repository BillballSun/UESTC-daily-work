typedef unsigned char Byte;

void Check_memory(void *source, size_t bytes)
{
	Byte *pointer=(Byte *)source;
	Byte temp;
	int count;
	printf("Target:%u    Length:%u\n", (unsigned int)source, (unsigned int)bytes);
	printf("Address   Bits      char  Value\n");
	printf("--------  --------  ----  -----\n");
	for(size_t i=1;i<=bytes;i++)
	{
		printf("%8.8u  ",(unsigned int)(pointer+i-1));
		temp=*(pointer+i-1);
		for(count=1;count<=8;count++)
			if(temp==0) break;
			else
			{
				printf("%d",(int)temp%2);
				temp=temp/2;
			}
		for(;count<=8;count++)
			printf("0");
		
		printf("     %c  %5u\n",*(pointer+i-1),(unsigned int)(*(pointer+i-1)));
	}
}
