#include<linux/init.h>
#include<linux/module.h>
#include<linux/interrupt.h>

MODULE_LICENSE("Dual BSD/GPL");

irqreturn_t irq_handler(int irq,void *dev_id)
{
	printk(KERN_ALERT "In %s:irq no:%d.\n",__func__,irq);
	return IRQ_HANDLED;
}

static int __init irq_init(void)
{
	request_irq(IRQ_EINT8,irq_handler,IRQF_TRIGGER_FALLING,"key1",NULL);//将key1这个中断注册到内核中
	printk(KERN_ALERT "Irq requested.\n");
	return 0;
}

static void __exit myirq_exit(void)
{
	free_irq(IRQ_EINT8,NULL);
	printk(KERN_ALERT "Irq freed.\n");
}

module_init(irq_init);
module_exit(myirq_exit);
