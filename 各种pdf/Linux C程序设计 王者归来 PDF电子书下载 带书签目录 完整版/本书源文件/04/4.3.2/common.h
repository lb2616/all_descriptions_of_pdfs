#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 定义一个自定义类型的函数指针，返回值是整型，两个参数是两个任意类型的指针 
* 该函数的两个参数分别是需要比较的两个对象，在比较时将其转换
* 如果大于则返回1，等于则返回0，小于则返回-1
*/
typedef int (*cmp)(void *, void *);

typedef struct book* Book;

/* 图书结构
* id : 图书的编号
* name : 图书的名字
*/
struct book{
	int id;
	char name[10];
};

/* 求最大对象的函数 */
extern void *max(void *array[], int len, cmp func);

/* 比较两个整数的函数 */
extern int cmp_int(void *p, void *q);
/* 比较两个图书结构的函数 */
extern int cmp_struct(void *p, void *q);

/* 插入一个结构 */
extern int insert_struct(Book *pos, int id, char * name);
/* 插入一个整数 */
extern int insert_int(int **pos, int val);
