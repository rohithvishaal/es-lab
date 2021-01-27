/* LED blinking*/
#include <LPC214X.H>
void delay(unsigned int count)
{
unsigned int i,j;
for(i=0;i<count;i++)
for(j=0;j<109;j++);
}
int main(void)
{
IODIR1=0x00ff0000;
while(1)
{
IOSET1=0x00550000;
delay(1000000);
IOCLR1=0x00550000;
delay(1000000);
}
}