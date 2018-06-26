/* CREATED BY ANBUJAKSH SHAH : DATE(05\08\2016): TIME :-01:59 PM
IN MY CASE  I HAVE CHOOSEN INITIAL LOOP 0 DEGREE THEN 
STEP FIRST (FOR 90 DEGREE):- A HIGH  PULSE OF 1500 US AND LOW PULSE  OF 18500 US IS RUN IN LOOP OF 20 ROUND.
STEP SECOND (FOR 180 DEGREE):-A HIGH PULSE OF 2200 US AND LOW PULSE OF  */

#define F_CPU 11059200UL
#include"avr/io.h"
#include<util/delay.h>
void T0Delay();
void T1Delay();
void T2Delay();
void T4Delay();
void T5Delay();
void T6Delay();
void main()
{
 
 
 DDRB = 0xFF;
int i,j,k;
_delay_ms(500);


 while(1)
 {


for (i=0;i<=20;i++)
 {
  PORTB|=(1<<0);
 // T0Delay();
  _delay_us(1500);
  PORTB&=~(1<<0);
// T4Delay();
 _delay_us(18500);
   
 }
 _delay_ms(800);

/*for (k=0;k<=20;k++)
 {
  PORTB|=(1<<0);
 T2Delay();
 // _delay_us(2250);
  PORTB&=~(1<<0);
T6Delay();
// _delay_us(17750);
   
 }
 _delay_ms(800);
*/  
for (j=0;j<=50;j++)
 {
  PORTB|=(1<<0);
  //T1Delay();
  _delay_us(8);
  PORTB&=~(1<<0);
// T5Delay();
 _delay_us(19992);
   
 }
 _delay_ms(800);
 }
 }
 void T0Delay()//for 1500 micro second
 {
  
  TCNT1H=(-15957)>>8;//0xC1;
  TCNT1L=(-15957);//0xAB;
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
  }
   void T4Delay()//for 18500 micro second
	{
	TCNT1H=(-3075)>>8;
  TCNT1L=(-3075);
  TCCR1A=0x00;
  TCCR1B=0x03;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
  
   }
void T1Delay()//for 8 micro second
 {
  TCNT1H=(-85)>>8;
  TCNT1L=(-85);
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
   }
   void T5Delay()//for 19992 micro second
	{
	TCNT1H=(-3323)>>8;
  TCNT1L=(-3323);
  TCCR1A=0x00;
  TCCR1B=0x03;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
  
   }
void T2Delay()//for 2250 micro second
 {
  TCNT1H=(-23936)>>8;//0xB1;
  TCNT1L=(-23936);
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
   }
void T6Delay()//for 17750 micro second
	{
	TCNT1H=(-2950)>>8;
  TCNT1L=(-2950);
  TCCR1A=0x00;
  TCCR1B=0x03;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
  
   }
