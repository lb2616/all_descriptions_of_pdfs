#include <stdio.h>

/* 声明四个全局变量 */
extern int (*p1)(int ,int);	/* 引用加法函数 */
extern int (*p2)(int ,int);	/* 引用减法函数 */
extern int (*p3)(int ,int);	/* 引用乘法函数 */
extern int (*p4)(int ,int);	/* 引用除法函数 */ 

/* 四则运算的函数声明 */
int add(int a, int b); 		/* 加法函数 */
int sub(int a, int b); 		/* 减法函数 */
int mul(int a, int b); 		/* 乘法函数 */
int div(int a, int b); 		/* 除法函数 */
