#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>

MODULE_LICENSE("Dual BSD/GPL");

#define GPGCON 0x56000060
#define GPGDAT 0x56000064

int* gpgcon=NULL;
int* gpgdat=NULL;

static int cdev_major=0;
module_param(cdev_major,int,S_IRUGO);

static dev_t devId;
static int baseminor=0;
static int count=1;
static char* devName="mykey";

static struct cdev chrdev;
static struct class *cls=NULL;
static struct device *dev=NULL;

static int key[6];

static int chrdev_open(struct inode* inode,struct file* filp){
	printk(KERN_ALERT "In %s:open chrdev.\n",__func__);
	gpgcon=ioremap(GPGCON,sizeof(int));
	gpgdat=ioremap(GPGDAT,sizeof(int));
	
	*gpgcon &= ~((0x03<<0)|(0x03<<6)|(0x03<<10)|(0x03<<12)|(0x03<<14)|(0x03<<22));

	return 0;
}
static int chrdev_close(struct inode* inode,struct file* filp){
	printk(KERN_ALERT "In %s:close chrdev.\n",__func__);
	iounmap(gpgcon);
	iounmap(gpgdat);
	return 0;
}

static ssize_t chrdev_read(struct file* filp,char __user * buff,size_t count, loff_t *offp){
	//key    1 2 3 4 5 6
	//GPGDAT 0 3 5 6 7 11

	//1:NOT press,0:press
	key[0]= (*gpgdat & (0x01<<0))?1:0;
	key[1]= (*gpgdat & (0x01<<3))?1:0;
	key[2]= (*gpgdat & (0x01<<5))?1:0;
	key[3]= (*gpgdat & (0x01<<6))?1:0;
	key[4]= (*gpgdat & (0x01<<7))?1:0;
	key[5]= (*gpgdat & (0x01<<11))?1:0;

	copy_to_user(buff,key,6*sizeof(int));
	printk(KERN_ALERT "In %s:read chrdev.\n",__func__);
	return 6*sizeof(int);
}
static ssize_t chrdev_write(struct file* filp,const char __user * buff,size_t count, loff_t *offp){
	printk(KERN_ALERT "In %s:Are you kidding?\n",__func__);
	return -1;
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

	if ((cls=class_create(THIS_MODULE,devName))==NULL){
		printk(KERN_ALERT "Can not create class.\n");
		return -1;
	}

	if ((dev=device_create(cls,NULL,devId,NULL,devName))==NULL){
		printk(KERN_ALERT "Can not create device.\n");
		return -1;
	}

	return 0;
}

static void __exit chrdev_exit(void){
	device_destroy(cls,devId);
	class_destroy(cls);
	cdev_del(&chrdev);
	unregister_chrdev_region(devId,count);
}

module_init(chrdev_init);
module_exit(chrdev_exit);

