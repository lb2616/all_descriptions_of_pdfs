#ifndef _MY_STU_H
#define _MY_STU_H

#define NAME_LEN 20

typedef struct MyPDU_Tag
{
	unsigned long length;
	char data[4];
}MyPDU;

#endif
