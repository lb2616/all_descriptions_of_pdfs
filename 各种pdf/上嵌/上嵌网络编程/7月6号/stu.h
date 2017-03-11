#ifndef _MY_STU_H
#define _MY_STU_H
#define NAME_LEN 20

typedef struct MyPDU_Tag
{
	char name[NAME_LEN];
	unsigned long number;
	float cScore;
	float mathScore;
	float chnScore;
	char sex;
	char rev[3];
}MyPDU;

#endif
