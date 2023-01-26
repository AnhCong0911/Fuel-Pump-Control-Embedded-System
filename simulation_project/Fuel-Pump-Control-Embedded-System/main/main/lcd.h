#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#define LCD_Dir DDRA
#define LCD_Port PORTA
#define RS PA2
#define EN PA3
#define tbi(port,bit) port ^= (1 << bit); 
#define cbi(port,bit) port &= ~(1 << bit);
#define sbi(port,bit) port |= (1 << bit);


void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
#endif /* LCD_H_ */