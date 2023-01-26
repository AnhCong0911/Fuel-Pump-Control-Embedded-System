#ifndef MAIN_H_
#define MAIN_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include <lcd.h>
#include <button.h>
#define tbi(port,bit) port ^= (1 << bit);
#define cbi(port,bit) port &= ~(1 << bit);
#define sbi(port,bit) port |= (1 << bit);
#endif /* MAIN_H_ */