#include<REG_MPC82G516.H>

void delay_us(int us);
void LOOP(); 

unsigned char input, output, temp, x, y;



void main()
{
	TMOD = 0x20;		//MOV TMOD, #00100000B
	PCON = PCON & 0xFF;	//ANL PCON, #11111111B
	TH1 = 0xF3;			//MOV TH1, #F3H
	TL1 = 0xF3;			//MOV TL1, #F3H
	TR1 = 1;			//SETB TR1
	SCON = 0xD0;
		
	temp = P0;
	input = '\0';
	while(1)
	{
		if(temp != P0)
		{
			x = P0>>4;
			y = P0 & 0x0F;
			
			if(x<10)output = x + '0';
			else output = x - 10 + 'a';
			LOOP();
			
			if(y<10)output = y + '0';
			else output = y - 10 + 'a';
			LOOP();
			
			P2 = P0;
			
			temp = P0;
			delay_us(50);
		}
		
		
		
		if(RI == 1){
				RI = 0;
				input = SBUF;
				
				P1 = ~input;
			
				/*output = input;
				LOOP();*/
			
				//input = '\0';
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
