#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LIBO");

extern int my_test(char *);

//static int count=5;
//module_param(count,int,S_IRUGO);//UGO USER GROUP OTHERS
static int __init hello_init(void)
{   
	char *param="Shanghai";
	printk(KERN_ALERT "In %s:ret =%d.\n",__func__,my_test(param));
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Goodbye module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

