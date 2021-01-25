#include<LPC214X.H>
int main ()
{
__asm
{
MOV R1,#0X40000000
MOV R2,#0X00
MOV R5,#0X03
STR R2,[R1],#4
ADD R2,#0X01
STR R2,[R1]
fibo: SUB R1,#0X04
LDR R3,[R1],#4
LDR R4,[R1],#4
ADD R3,R4
STR R3,[R1]
SUB R5,#0X01
CMP R5, #0X00
BNE fibo
}
}