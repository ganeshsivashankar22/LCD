#include<LPC21xx.h>
#define LCD 0xff
#define RS  1<<8
#define E   1<<9
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_CGRAM(void);
unsigned char cgram_lut[]={0x00,0x00,0x0e,0x1f,0x11,0x11,0x1f,0x00,0x00,0x04,0x0e,0x1f,0x11,0x11,0x1f,0x00,0x04,0x04,0x0e,0x1f,0x11,0x11,0x1f,0x00};
void delay(int ms)
{
int i;
for(;ms>0;ms--)
for(i=12000;i>0;i--);
}
 int main()
 {
 LCD_INIT();
 LCD_CGRAM();
 LCD_CMD(0x80);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x80);
 LCD_DATA(1);
 delay(500);
 LCD_CMD(0x80);
 LCD_DATA(2);
 delay(500);
 }
 void LCD_INIT(void)
 {
	  IODIR0=LCD|RS|E;
	  LCD_CMD(0x01);
	  LCD_CMD(0x02);
	  LCD_CMD(0x0c);
	  LCD_CMD(0x38);
	  LCD_CMD(0x80);
	                    
 }
 void LCD_CMD(unsigned char s)
 {
  IOCLR0=LCD;
  IOSET0=s;
  IOCLR0=RS;
  IOSET0=E;
  delay(2);
  IOCLR0=E;
  }
  void LCD_DATA(unsigned char s)
  {
  IOCLR0=LCD;
  IOSET0=s;
  IOSET0=RS;
  IOSET0=E;
  delay(2);
  IOCLR0=E;
  }
  void LCD_CGRAM(void)
  {
  int i=0;
  LCD_CMD(0x40);
   for(i=0;i<24;i++)
   LCD_DATA(cgram_lut[i]);

  }
 