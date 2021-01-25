#include<LPC214X.H>
int main ()
{
__asm
{
MOV R0,#0X40000000
MOV R1,#0X05
MOV R2,#0X01
ABC :MUL R3,R1,R2
	STR R3,[R0]
	ADD R2,#0X01
	CMP R2,#0X0A
	BLE ABC 
}
}

