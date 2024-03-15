void interrupt() //interruption
{ 
if (INTCON.B1==1)
{


while (INTCON.B1==1) {
PORTB.B1=1 ;
PORTB.B2=1 ;
PORTB.B3=1 ;
delay_ms(1000) ;
PORTB.B3=0 ;
delay_ms(1000) ;
}
}
}
void main() {
TRISA=0X0F ;
TRISB=0X01 ;
CMCON=0X01 ;
INTCON=0b10010000 ; //RBO INT  GIE=1 et INTE=1
option_reg=0b11000000 ;
PORTB=0X00 ;
for (;;)
{
if(CMCON.B7==1 && CMCON.B6==1)
{
PORTB.B1=1 ;
PORTB.B2=0 ;
}
if(CMCON.B7==0 && CMCON.B6==1)
{
PORTB.B1=0 ;
PORTB.B2=0 ;
}
if(CMCON.B7==0 && CMCON.B6==0)
{
PORTB.B1=0 ;
PORTB.B2=1 ;
}
}
}