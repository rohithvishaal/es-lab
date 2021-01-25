#include<lpc214x.h>
#include<stdio.h>
#include<LCD-16x2-8bit.h>
#include<string.h>
int main(void)
{
	uint32_t result;
	float voltage;
	char volt[18];
	LCD_init();
	PINSEL1 = 0x01000000 // port .028 is set as AD0.1
	AD0CR = 0x00200402 // ADC operational 10 -bits , 11 clocks for conversion
	while(true){
		AD0CR = AD0CR | (1<<24) // start conversion
		while(!(AD0DR1 & 0x80000000));
		result = AD0DR1;
		result>>=6;
		result&=0x000003FF;
		voltage = ((result/1023.0)*3.3); // convert ADC to its equivalent voltage
		LCD_Command(0x80);
		sprintf(volt, "Voltage=%.2fV",voltage);
		LCD_String(volt);
		memeset(volt,0,18);
	}
}