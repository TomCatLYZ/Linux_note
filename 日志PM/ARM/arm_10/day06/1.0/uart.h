#ifndef __UART_H
#define __UART_H

/*函数声明*/
extern void uart_init(void); //初始化串口
extern void uart_putc(char c);//发送字符函数
extern void uart_puts(char *s);//发送字符串函数

#endif
