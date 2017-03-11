#include<linux/init.h>
#include<linux/module.h>
#include<linux/interrupt.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/io.h>
#include<linux/delay.h>

#define GPBCON 0x56000010
#define GPBDAT 0x56000014

static int* gpbcon=NULL;
static int* gpbdat=NULL;
static struct task_struct *mytask=NULL;
static int time;
static int loop=1;
static int start=0;
MODULE_LICENSE("Dual BSD/GPL");

irqreturn_t irq_handler(int irq,void *dev_id)
{
	printk(KERN_ALERT "In %s:irq no:%d.\n",__func__,irq);
	switch(irq)
	{
		case IRQ_EINT8:
			printk(KERN_ALERT "key 1 pressed.\n");
			start=0;
			*gpbdat |=(0x01<<0);
			break;
		case IRQ_EINT11:
			printk(KERN_ALERT "key 2 pressed.\n");
			start=0;
			*gpbdat &= ~(0x01<<0);
			break;
		case IRQ_EINT13:
			printk(KERN_ALERT "key 3 pressed.\n");
			time=500;
			start=1;
			break;
		case IRQ_EINT14:
			printk(KERN_ALERT "key 4 pressed.\n");
			if(time>20)
				time -=20;
			start=1;
			break;
		case IRQ_EINT15:
			printk(KERN_ALERT "key 5 pressed.\n");
			if(time<2000)
				time +=50;
			start=1;
			break;
		case IRQ_EINT19:
			printk(KERN_ALERT "key 6 pressed.\n");
			loop=0;
			break;
		default:
			break;
	}
	return IRQ_HANDLED;
}

int buzzer_thread(void *data)
{   
	while(loop)
	{
		if(start)
		{
			*gpbdat |=(0x01<<0);
			mdelay(time);
			*gpbdat &=~(0x01<<0);
			mdelay(time);
		}
		if(kthread_should_stop())
			break;
    }
	return 0;
}
static int __init myirq_init(void)
{
   	request_irq(IRQ_EINT8,irq_handler,IRQF_TRIGGER_FALLING,"key1",NULL);//将key1这个中断注册到内核中
   	request_irq(IRQ_EINT11,irq_handler,IRQF_TRIGGER_FALLING,"key2",NULL);//将key1这个中断注册到内核中
   	request_irq(IRQ_EINT13,irq_handler,IRQF_TRIGGER_FALLING,"key3",NULL);//将key1这个中断注册到内核中
   	request_irq(IRQ_EINT14,irq_handler,IRQF_TRIGGER_FALLING,"key4",NULL);//将key1这个中断注册到内核中
   	request_irq(IRQ_EINT15,irq_handler,IRQF_TRIGGER_FALLING,"key5",NULL);//将key1这个中断注册到内核中
   	request_irq(IRQ_EINT19,irq_handler,IRQF_TRIGGER_FALLING,"key6",NULL);//将key1这个中断注册到内核中
	gpbcon=ioremap(GPBCON,sizeof(int));
	gpbcon=ioremap(GPBDAT,sizeof(int));
	
	*gpbcon |=(0x01<<0);
	*gpbcon &=~(0x01<<1);

	*gpbdat &=~(0x01<<0);

	if(mytask==NULL)
		kthread_run(buzzer_thread,NULL,"buzzer");
//	printk(KERN_ALERT "Irq requested.\n");

	printk(KERN_ALERT "Irq requested.\n");
	return 0;
}

static void __exit myirq_exit(void)
{
	free_irq(IRQ_EINT8,NULL);
	free_irq(IRQ_EINT11,NULL);
	free_irq(IRQ_EINT13,NULL);
	free_irq(IRQ_EINT14,NULL);
	free_irq(IRQ_EINT15,NULL);
	free_irq(IRQ_EINT19,NULL);
	printk(KERN_ALERT "Irq freed.\n");
}

module_init(myirq_init);
module_exit(myirq_exit);
