#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*小字典结构体*/
typedef struct dictionary
{	
	int ID;
	char simpname[20];
	char wholename[100];
	char chinesename[100];	
}DIC;

typedef struct STNODE
{
	DIC diction;
	struct stnode *next;
}STNODE;

static int choice1=0;
//主界面
int  MainUI()
{
    int iChoice = 0;
    system("clear");     
    printf("\n\t****************************************************************\n");
    printf("\t*                                                              *\n");
    printf("\t          ——————欢迎使用协议缩写小字典——————                  \n");
    printf("\t*                                                              *\n");
    printf("\t****************************************************************\n");
    printf("\t                                                                \n");
    printf("\t                       相关操作选项                           \n");
    printf("\t                                                                \n");
    printf("\t****************************************************************\n");
    printf("\t*                     0.安全退出系统                           *\n");
    printf("\t*                     1.添加字典内容                           *\n");
    printf("\t*                     2.删除字典内容                           *\n");
    printf("\t*                     3.修改字典内容                           *\n");
    printf("\t*                     4.查找字典内容                           *\n");
    printf("\t*                     5.显示字典内容                           *\n");
    printf("\t****************************************************************\n");

    printf("请输入功能编号1~5, 0 表示退出:");
    scanf("%d",&iChoice);
    return iChoice;
}

//读文件取出当前文件中最大的ID编号
int readfileID(char filename[25])
{
    struct dictionary sj;
    int bianhaoID;
    int filepos=0;
    FILE *file=NULL;
    file=fopen(filename,"rt");
    if(file==NULL)
    {
        printf("打开文件%s出错！\n",filename);
        return 0;
    }
    fseek(file,0,SEEK_END);
    filepos=ftell(file);//报告文件距离文件开头的位移量，如果为0，则表示文件为空
    if(filepos==0)
    {
        return 1;
    }
    else
    {
        fseek(file,-sizeof(struct dictionary),SEEK_END);//放在文件末尾之前的一个结构体处
        fread(&sj,sizeof(struct dictionary),1,file);
        bianhaoID=sj.ID+1;
        printf("%d\n",bianhaoID);
        fclose(file);
        file=NULL;
        return bianhaoID;
    }
}

//添加字典信息
void Adddicinfo()
{
	FILE *fp;
	struct dictionary dic;
	fp=fopen("dictionary.txt","at");
	if(fp==NULL)
	{
		printf("文件打开错误!\n");
	}
	dic.ID=readfileID("dictionary.txt");
	printf("请输入缩写的字符：");
	scanf("%s",dic.simpname);
	fflush(stdin);
	printf("请输入全称：");
	scanf("%s",dic.wholename);
	fflush(stdin);
	printf("请输入中文解释：");
	scanf("%s",dic.chinesename);
	fflush(stdin);
	fwrite(&dic,sizeof(struct dictionary),1,fp);
	fclose(fp);
}

//销毁链表---砍头法
void DestroyLinklist(STNODE *head)
{
     STNODE *q=head->next;
     while(q!=NULL)
     {
       head->next=q->next;
       free(q);
       q=head->next;
     } 
}

//保存函数
void save(STNODE head,FILE *file)
{
    while(head.next!=NULL)  //因为是以w的形式打开的文件，所以不论是否修改，都要重写文件
    {
         fwrite(&head.next->person,sizeof(struct PERSONINFO),1,file);
         head.next=head.next->next;
    }
}

//读文件到链表的子函数
STNODE * readfiletolist(FILE *file)
{
	STNODE *head=malloc(sizeof(struct STNODE));
	DIC people;
    if(file==NULL)
    {
        printf("打开文件出错！\n");
        return;
    }
    else
    {
        while((fread(&people,sizeof(struct DIC),1,file))==1)//利用尾插法将文件中读取的信息临时存储在链表中
        {
            STNODE *p=malloc(sizeof(struct STNODE));//1-1创建一个新结点p
            if(head.next==NULL)
            {
                head.next=p;
                p->next=NULL;
                p->person=people;
            }
            else
            {
                STNODE *tmp=head;
                while(tmp->next!=NULL)  //将指针移动到链表的尾部，即最后一个元素的地方
                    tmp=tmp->next;
                tmp->next=p;
                p->next=NULL;
                p->person=people;
            }
        }//end of while   
    }// end of else
    return head;
}

//按缩写名查找并返回地址
STNODE *findname()
{
	
}

//按缩写名或编号查找并返回地址
void find()
{
	char word[30];
	int choice,id;
	printf("请输入choice的值　1: 按缩写名删除 2:按编号删除\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("请输入缩写名:");
			scanf("%s",word);
			break;
		case 2:
			printf("请输入编号:");
			scanf("%d",&id);
			break;
	}
}

//删除字典信息
void deletedicinfo()
{
	STNODE *head=NULL;
	head=readfiletolist("dictionary.txt");
	
	while(head->next!=NULL)
	{
		
	}
}



//找到或没找到的提示函数
void tishi(int found,DIC dic)
{
    if(found==1)
    {
        printf("您想要查找的信息如下\n");
        printf("\t%-8s%-8s%-60s%-6s%-30s\n","编号","  简称","    全"  ,  "称","中文翻译");
        printf("\t%-8d%-8s%-60s%-30s \n",
                dic.ID,dic.simpname,dic.wholename,dic.chinesename);  
    }
    if(found==0&&choice1==1)
    {
        printf("在文件中没有找到此单词的相关纪录！！！\n");
    }
    if(found==0&&choice1==2)
    {
        printf("在文件中没有找到此单词的人员的相关纪录！！！\n");
    }  
}
//按名字或编号查找的子函数
void foundnameorID(DIC people,int choice,int found,FILE *file)
{   
    int personID;
    char personname[48];
    switch(choice)
        {
         case 1:
              printf("请输入您想查找的单词名：");
              scanf("%s",personname);
              while((fread(&people,sizeof(struct dictionary),1,file))==1)
              {
                  if((strcmp(people.simpname,personname))==0)
                  {
                      found=1;
                      break;
                  }  
              }
              break;
         case 2:
              printf("请输入您想查找的单词编号：");
              scanf("%d",&personID);
              while((fread(&people,sizeof(struct dictionary),1,file))==1)
              {
                  if(personID==people.ID)
                  {
                      found=1;
                      break;
                  }  
              }
             break;
        }
        tishi(found,people);
}

//按名字或编号查找的函数
void searchnameorID(char filename[25])
{
    DIC people;
    int found=0,choice;
    FILE *file=NULL;
    file=fopen(filename,"rt");
    if(file==NULL)
    {
        printf("打开文件%s出错！\n",filename);
        return;
    }
    else
    {
        rewind(file);
        printf("请输入choice的值 1：按单词名查找  2：按编号查找\n");
        scanf("%d",&choice);
        choice1=choice;
        foundnameorID(people,choice,found,file);//按名字或编号查找的子函数的调用
    }//end of else
    fclose(file);
    file=NULL;
}

//读文件并且打印数据的函数
void showdicinfo(char filename[25])
{
    struct dictionary dic;
    FILE *file=NULL;
    file=fopen(filename,"rt");
    if(file==NULL)
    {
        printf("打开文件%s出错！\n",filename);
        return;
    }
    rewind(file);
    fread(&dic,sizeof(struct dictionary),1,file);
    printf("\t\t\t全文信息如下"); 
    printf("\n\t====================================================================================================================\n");
    printf("\t%-8s%-8s%-60s%-6s%-30s\n","编号","  简称","    全"  ,  "称","中文翻译");
    while(!feof(file))//读取数据并打印
    {
		printf("\t%-8d%-8s%-60s%-30s \n",
                dic.ID,dic.simpname,dic.wholename,dic.chinesename);         
        fread(&dic,sizeof(struct dictionary),1,file);
    }        
    printf("\t====================================================================================================================\n");
    fclose(file);
    file=NULL; 
    return;
}

int main()
{   
	int ret;
    while(1)
    {
    	ret=MainUI();
	    switch(ret)
	    {
		    case 1:
		    	Adddicinfo();
            	while(getchar() == '\n');
		    	break;
	/*	    case 2:
		    	deletedicinfo();
            	while(getchar() == '\n');
		    	break;
	        case 3:
		    	Modifydicinfo();
                while(getchar() == '\n');
		    	break;*/
            case 4:
                searchnameorID("dictionary.txt");
                while(getchar() == '\n');
		    	break; 
			case 5:
                showdicinfo("dictionary.txt");
                while(getchar() == '\n');
		    	break;  
        }
             if(0==ret)
             	exit(-1);
	}
    return 0;
}
























