#include<REG_MPC82G516.H>

void delay_us(int us);
void LOOP(); 

unsigned char input;

void main()
{

	TMOD = 0x20;		//MOV TMOD, #00100000B
	PCON = PCON & 0xFF;	//ANL PCON, #11111111B
	TH1 = 0xF3;			//MOV TH1, #F3H
	TL1 = 0xF3;			//MOV TL1, #F3H
	TR1 = 1;			//SETB TR1
	SCON = 0xD0;
	
	input = ' ';
	LOOP();
	
	for(input = 'a'; input<='z'; ++input)
		LOOP();
	for(input = 'A'; input<='Z'; ++input)
		LOOP();
}

void LOOP()
{
	SBUF = input;
	delay_us(50);
	while(TI == 0);
	TI = 0;
}

void delay_us(int us)
{                  
		unsigned int i;
   while(us--)
	 {
			i = 1000;
			while(i--);
	 }
}
