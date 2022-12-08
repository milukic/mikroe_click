/*
 * clickUART.h
 *
 * Created: 26-Aug-19 5:49:25 PM
 *  Author: Milan Lukic
 */ 

#ifndef CLICKUART_H_
#define CLICKUART_H_

#include <atmel_start.h>

void clickUARTinit(void);
uint16_t clickUARTavailable(void);
void clickUARTputChar(char c);
void clickUARTputSample(uint8_t sample);
void clickUARTputString(char *str);
char clickUARTgetChar(void);
uint8_t clickUARTgetString(char *str);
void clickUARTsendHex(uint8_t hex);
void clickUARTflush(void);

#endif /* CLICKUART_H_ */