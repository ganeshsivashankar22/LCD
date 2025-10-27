  #include<LPC21xx.h>

#define LCD 0xff<<0

#define RS 1<<8

#define E 1<<9

void delay(int ms)


{

int i;

for(;ms>0;ms--)

for(i=12000;i>0;i--);

}


void LCD_INIT(void)	;

void LCD_CMD(unsigned char);

void LCD_DATA(unsigned char);

void LCD_STRING(unsigned char *);

void LCD_CGRAM(void);

void LCD_INTEGER( int);

 unsigned char cgram_lut[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x0d ,0x00};

int main()

{

 int count=0; 

LCD_INIT();


while(1)

{
 LCD_CMD(0x80);
 LCD_STRING("switch count:");
  LCD_CMD(0xc0);
   LCD_INTEGER(count);

if((IOPIN0&1<<14)==0)
{
 delay(500);
 count++;
}
}

}

void LCD_INIT(void)

{

IODIR0=0x000003ff;

LCD_CMD(0x01);

LCD_CMD(0x02);

LCD_CMD(0x0c);

LCD_CMD(0x38);

LCD_CMD(0x80);

}

void LCD_CMD(unsigned char cmd)

{

IOCLR0=LCD;

IOSET0=cmd;

IOCLR0=RS;

IOSET0=E;

delay(2);

IOCLR0=E;

}


void LCD_DATA(unsigned char d)

{

IOCLR0=LCD;

IOSET0=d;

IOSET0=RS;

IOSET0=E;

delay(2);

IOCLR0=E;

}

void LCD_STRING(unsigned char* s)

		{

		int pos=0;

		while(*s)

		{

		LCD_DATA(*s++);

		pos++;

		if(pos==15)

		LCD_CMD(0x40);

		}

		}

void LCD_CGRAM(void)

		 {

		 int i;

		 LCD_CMD(0x40);

		 for(i=0;i<8;i++)

		 LCD_DATA(cgram_lut[i]);

		 }

void LCD_INTEGER(int n)

{

unsigned char a[5];

int i=0;

if(n==0)  

{


LCD_DATA('0');

}

else

{

if(n<0)

{

LCD_DATA('-');

n=-n;

}

while(n>0)

{

 a[i++]=n%10;

 n=n/10;

}

for(i=i-1;i>=0;i--)
LCD_DATA(a[i]+48);
}
}