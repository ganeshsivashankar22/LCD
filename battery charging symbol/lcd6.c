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


 unsigned char cgram_lut[]={0x0e,0x1b,0x11,0x11,0x11,0x11,0x1f ,0x00,0x0e,0x1b,0x11,0x11,0x11,0x1f,0x1f,0x00,0x0e,0x1b,0x11,0x11,0x1f,0x1f,0x1f,0x00,0x0e,0x1b,0x11,0x1f,0x1f,0x1f,0x1f,0x00,0x0e,0x1b,0x1f,0x1f,0x1f,0x1f,0x1f,0x00,0x0e,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x00};


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
LCD_CMD(0x80);
LCD_DATA(3);
delay(500);
LCD_CMD(0x80);
LCD_DATA(4);
delay(500);
LCD_CMD(0x80);
LCD_DATA(5);
delay(500);





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


		 for(i=0;i<48;i++)


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