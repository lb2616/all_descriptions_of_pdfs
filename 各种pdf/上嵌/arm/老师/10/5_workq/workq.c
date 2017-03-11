#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

MODULE_LICENSE("Dual BSD/GPL");
//static struct tasklet_struct mytasklet;
static struct work_struct myworkq;

irqreturn_t irq_handler(int irq,void* dev_id){//up half part
	printk(KERN_ALERT "In %s: irq no: %d.\n",__func__,irq);
//	tasklet_schedule(&mytasklet); //schedule bottom half part
	schedule_work(&myworkq);
	return IRQ_HANDLED;
}

//void mytasklet_action(unsigned long data){ //bottom half part
void myworkq_action(struct work_struct *work){
	printk(KERN_ALERT "1. In %s: bottom half\n",__func__);
//	mdelay(500); //NEVER use msleep
	msleep(500); //Can use msleep
	printk(KERN_ALERT "2. In %s: bottom half\n",__func__);

}

static int __init myirq_init(void){
	request_irq(IRQ_EINT8,irq_handler,IRQF_TRIGGER_FALLING,"key1",NULL);
//	tasklet_init(&mytasklet,mytasklet_action,0);
	INIT_WORK(&myworkq,myworkq_action);
	printk(KERN_ALERT "Irq requested.\n");
	return 0;
}

static void __exit myirq_exit(void){
	free_irq(IRQ_EINT8,NULL);
	printk(KERN_ALERT "Irq freed.\n");
}

module_init(myirq_init);
module_exit(myirq_exit);
