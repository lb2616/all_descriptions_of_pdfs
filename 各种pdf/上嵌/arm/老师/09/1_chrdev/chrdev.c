#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
MODULE_LICENSE("Dual BSD/GPL");

static int cdev_major=0;
module_param(cdev_major,int,S_IRUGO);

static dev_t devId;
static int baseminor=0;
static int count=1;
static char* devName="mychrdev";

static struct cdev chrdev;

static int chrdev_open(struct inode* inode,struct file* filp){
	printk(KERN_ALERT "In %s:open chrdev.\n",__func__);
	return 0;
}
static int chrdev_close(struct inode* inode,struct file* filp){
	printk(KERN_ALERT "In %s:close chrdev.\n",__func__);
	return 0;
}

static ssize_t chrdev_read(struct file* filp,char __user * buff,size_t count, loff_t *offp){
	printk(KERN_ALERT "In %s:read chrdev.\n",__func__);
	return 1;
}
static ssize_t chrdev_write(struct file* filp,const char __user * buff,size_t count, loff_t *offp){
	printk(KERN_ALERT "In %s:write chrdev.\n",__func__);
	return 1;
}

static struct file_operations fops={
		.owner=THIS_MODULE,
		.open=chrdev_open,
		.release=chrdev_close,
		.read=chrdev_read,
		.write=chrdev_write,
};

static int __init chrdev_init(void){
	int result;
	if (cdev_major>0){
		devId=MKDEV(cdev_major,baseminor);
		result=register_chrdev_region(devId,count,devName);
	}else{
		result=alloc_chrdev_region(&devId,baseminor,count,devName);
		cdev_major=MAJOR(devId);
	}

	if (result<0){
		printk(KERN_ALERT "Error in register/alloc chrdev_region.\n");
		return result;
	}

	printk("Success to get dev ID:%d,%d.\n",cdev_major,baseminor);
	
	cdev_init(&chrdev,&fops);
	chrdev.owner=THIS_MODULE;
	chrdev.ops=&fops;

	result=cdev_add(&chrdev,devId,count);//success:0,fail:-1
	if (result<0){
		printk(KERN_ALERT "Can not add chr dev.\n");
		return result;
	}

	return 0;
}

static void __exit chrdev_exit(void){
	cdev_del(&chrdev);
	unregister_chrdev_region(devId,count);
}

module_init(chrdev_init);
module_exit(chrdev_exit);

