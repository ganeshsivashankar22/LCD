		  #include<LPC21xx.h>
#define LCD 0xff
#define RS  1<<8
#define E   1<<9
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_CGRAM(void);
unsigned char cgram_lut[]={0x00,0x0e,0x1f,0x1f,0x1f,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
void delay(int ms)
{
int i;
for(;ms>0;ms--)
for(i=12000;i>0;i--);
}
 int main()
 {
 while(1)
 {
 LCD_INIT();
 LCD_CGRAM();
 LCD_CMD(0x80);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x80);
 LCD_DATA(1);
 LCD_CMD(0xc1);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xc1);
 LCD_DATA(1);
 LCD_CMD(0x82);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x82);
 LCD_DATA(1);
 LCD_CMD(0xc3);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xc3);
 LCD_DATA(1);
 LCD_CMD(0x84);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x84);
 LCD_DATA(1);
 LCD_CMD(0xc5);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xc5);
 LCD_DATA(1);
 LCD_CMD(0x86);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x86);
 LCD_DATA(1);
 LCD_CMD(0xc7);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xc7);
 LCD_DATA(1);
 LCD_CMD(0x88);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x88);
 LCD_DATA(1);
 LCD_CMD(0xc9);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xc9);
 LCD_DATA(1);
 LCD_CMD(0x8a);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x8a);
 LCD_DATA(1);
 LCD_CMD(0xcb);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xcb);
 LCD_DATA(1);
 LCD_CMD(0x8c);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x8c);
 LCD_DATA(1);
 LCD_CMD(0xcd);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xcd);
 LCD_DATA(1);
 LCD_CMD(0x8e);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0x8e);
 LCD_DATA(1);
 LCD_CMD(0xcf);
 LCD_DATA(0);
 delay(500);
 LCD_CMD(0xcf);
 LCD_DATA(1);
 }

 
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
   for(i=0;i<16;i++)
   LCD_DATA(cgram_lut[i]);

  }