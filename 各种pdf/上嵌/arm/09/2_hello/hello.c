#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LIBO");
static int count=5;
module_param(count,int,S_IRUGO);//UGO USER GROUP OTHERS
static char * output="module";
module_param(output,charp,S_IRUGO);
static int __init hello_init(void)
{   
	int i;
	for(i=0;i<count;i++)
	{
		printk(KERN_ALERT "hello %s\n",output);
	}
		return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Goodbye module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

