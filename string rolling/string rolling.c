 #include<LPC21xx.h>
 #include<string.h>
 #define LCD 0xff<<0
#define RS 1<<8
#define E 1<<9
void delay(int ms)
{
int i;
for(;ms>0;ms--)
for(i=12000;i>0;i--);
}
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char*);

 int main()
{
 int i;
 char str[20]="taramani";
 int j;
 LCD_INIT();
 
 while(1)
 {
 for(i=0,j=strlen(str)-1;i<16;i++)
 {
       if(i>=(16-j))
	   {
	   LCD_CMD(0x80);
	   LCD_STRING(&str[j]);
	   j--;
	   }
	   
	 LCD_CMD(0x80+i);
	 LCD_STRING("taramani");
	 delay(1000);
	 LCD_CMD(0x01);
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

void LCD_STRING(unsigned char *p)
{
while(*p)
{
LCD_DATA(*p);
p++;
}
}

