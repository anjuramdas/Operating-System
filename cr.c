#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/proc_fs.h>
#include<asm/uaccess.h>

int init_module()
{
int c;
c=read_cr3();
printk(KERN_INFO "Value of cr3 register : %d \n",c);
return 0;    

}

void cleanup_module(void){
	printk(KERN_ALERT"BYE\n");
}

