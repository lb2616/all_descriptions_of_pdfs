#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liao Xiaofei");

int my_test(char* str){
	printk(KERN_ALERT "In %s:%s\n",__func__,str);
	return 1;
}
EXPORT_SYMBOL(my_test);
