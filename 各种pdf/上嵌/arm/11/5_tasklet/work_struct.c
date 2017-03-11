#include<linux/init.h>
#include<linux/module.h>
#include<linux/interrupt.h>
#include<linux/delay.h>
MODULE_LICENSE("Dual BSD/GPL");

static struct work_struct myworkq;
//void myworkq_action(struct work_struct *work);
irqreturn_t irq_handler(int irq,void *dev_id)
{
	printk(KERN_ALERT "In %s:irq no:%d.\n",__func__,irq);
//	tasklet_schedule(&mytasklet); //schedule bottom half part
//	INIT_WORK(&myworkq,myworkq_action);
	schedule_work(&myworkq);
	return IRQ_HANDLED;
}

void myworkq_action(struct work_struct *work)
{
	printk(KERN_ALERT "1. In %s:bottom half\n",__func__);
//	mdelay(500);//never use msleep
	msleep(500); //can use msleep
	printk(KERN_ALERT "2. In %s:bottom half\n",__func__);
}

static int __init irq_init(void)
{
	request_irq(IRQ_EINT8,irq_handler,IRQF_TRIGGER_FALLING,"key1",NULL);//将key1这个中断注册到内核中
//	tasklet_init(&mytasklet,mytasklet_action,0);
//	schedule_work(&myworkq);
	INIT_WORK(&myworkq,myworkq_action);
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
