#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/io.h>
#include <linux/delay.h>

#define GPBCON 0x56000010
#define GPBDAT 0x56000014

static int* gpbcon=NULL;
static int* gpbdat=NULL;
static struct task_struct *mytask=NULL;
static int time=500;

MODULE_LICENSE("Dual BSD/GPL");

irqreturn_t irq_handler(int irq,void* dev_id){
	switch(irq){
		case IRQ_EINT8:
			printk(KERN_ALERT "Key 1 pressed.\n");
			time=100;
			break;
		case IRQ_EINT11:
			printk(KERN_ALERT "Key 2 pressed.\n");
			time=1000;
			break;
		default:
			break;
	}
	return IRQ_HANDLED;
}

int buzzer_thread(void* data){
	while(1){
		*gpbdat |= (0x01<<0);
		mdelay(time);
		*gpbdat &= ~(0x01<<0);
		mdelay(time);
		
		if (kthread_should_stop())
			break;
	}
	return 0;
}

static int __init myirq_init(void){
	request_irq(IRQ_EINT8, irq_handler,IRQF_TRIGGER_FALLING,"key1",NULL);
	request_irq(IRQ_EINT11,irq_handler,IRQF_TRIGGER_FALLING,"key2",NULL);
	gpbcon=ioremap(GPBCON,sizeof(int));
	gpbdat=ioremap(GPBDAT,sizeof(int));

	*gpbcon |=  (0x01<<0);
	*gpbcon &= ~(0x01<<1);

	*gpbdat &= ~(0x01<<0);

	if (mytask==NULL)
		kthread_run(buzzer_thread,NULL,"buzzer");

	printk(KERN_ALERT "Irq requested.\n");
	return 0;
}

static void __exit myirq_exit(void){
	free_irq(IRQ_EINT8,NULL);
	*gpbdat &= ~(0x01<<0);
	iounmap(gpbcon);
	iounmap(gpbdat);
	printk(KERN_ALERT "Irq freed.\n");
}

module_init(myirq_init);
module_exit(myirq_exit);
