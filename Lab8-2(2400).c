#include<REG_MPC82G516.H>

void delay_us(int us);
void LOOP(); 

unsigned char input, output;

void main()
{
	
	TMOD = 0x20;		//MOV TMOD, #00100000B
	PCON = PCON & 0xFF;	//ANL PCON, #11111111B
	TH1 = 0xF3;			//MOV TH1, #F3H
	TL1 = 0xF3;			//MOV TL1, #F3H
	TR1 = 1;			//SETB TR1
	SCON = 0xD0;
	
	
	while(1)
	{
		input = '\0';
		while(input == '\0'){
			if(RI == 1)
			{
				RI = 0;
				input = SBUF;
			}
		}
		
		switch (input)
		{
			case 'q':case 'Q':
				output = 'Q';
				LOOP();
				output = 'A';
				LOOP();
				output = 'Q';
				LOOP();
				break;
			case 'w':case 'W':
				output = 'w';
				LOOP();
				output = 'w';
				LOOP();
				output = 'w';
				LOOP();
				output = 'w';
				LOOP();
				output = 'w';
				LOOP();
				break;
			case 'e':case 'E':
				output = 'N';
				LOOP();
				output = 'C';
				LOOP();
				output = 'T';
				LOOP();
				output = 'U';
				LOOP();
				break;
			case 'r':case 'R':
				output = 'C';
				LOOP();
				output = 'S';
				LOOP();
				output = 'I';
				LOOP();
				output = 'E';
				LOOP();
				break;
		}
	}
	
}

void LOOP()
{
	SBUF = output;
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
