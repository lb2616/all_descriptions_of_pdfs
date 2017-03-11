#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liao Xiaofei");

static int __init hello_init(void){
	printk(KERN_ALERT "Hello module.\n");
	return 0;
}

static void __exit hello_exit(void){
	printk(KERN_ALERT "Goodbye module.\n");
}

module_init(hello_init);
module_exit(hello_exit);
