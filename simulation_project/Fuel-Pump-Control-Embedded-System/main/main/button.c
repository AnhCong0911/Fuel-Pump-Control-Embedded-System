#include <button.h>

void Speed_up(unsigned int *PWM1, unsigned int *PWM2 ,unsigned int Temp1, unsigned int Temp2 )
{
	_delay_ms(5);
	if(((PINB & (1 << button_up)) == 0) && (PORTD == (1 << PIND1)))
	{
		while(((PINB & (1 << button_up)) == 0) && (PORTD == (1 << PIND1)));
		*PWM1 += Temp1;
		*PWM2 += Temp2;
		if(*PWM1>=9600) *PWM1 = 9600;
		if(*PWM2>=15999) *PWM2 = 15999;
	}
}

void Speed_down(unsigned int *PWM1, unsigned int *PWM2 ,unsigned int Temp1, unsigned int Temp2 )
{
	if(*PWM1 >= 2500)
	{
		_delay_ms(5);
		if(((PINB & (1 << button_dowm)) == 0) && (PORTD == (1 << PIND1)))
		{
			while(((PINB & (1 << button_dowm)) == 0) && (PORTD == (1 << PIND1)));
			*PWM1 -= Temp1;
			*PWM2 -= Temp2;
			if(*PWM1 <= 600) *PWM1 = 1500;
			if(*PWM2 <= 1000) *PWM2 = 2500;
		}
	}
	else 
	{
		*PWM1 = Temp1;
		*PWM2 = Temp2;
	}
}

void On_Off(unsigned int *PWM1, unsigned int *PWM2 ,unsigned int Temp1, unsigned int Temp2)
{
	_delay_ms(5);
	if((PINB & (1 << button_start)) == 0)
	{
		while((PINB & (1 << button_start)) == 0);
		tbi(PORTD, 1);
		if(PORTD == (0 << PIND1)){
			
			*PWM1 = 0;
			*PWM2 = 0;
			
		}
		else
		{
			*PWM1 = Temp1; // on tang tu tu
			*PWM2 = Temp2;
			
		}
	}
}
