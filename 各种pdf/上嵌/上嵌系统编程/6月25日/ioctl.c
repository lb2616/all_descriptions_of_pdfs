#include<stdio.h>
#include<sys/ioctl.h>
#include<linux/fb.h>
#include <fcntl.h>

int main()
{
    struct fb_var_screeninfo var_info;
    struct fb_fix_screeninfo fix_info;
    int fd;
    fd=open("/dev/fb0",O_RDONLY);
    if(fd<0)
    {
        perror("open()");
        return -1;
    }
    ioctl(fd,FBIOGET_VSCREENINFO,&var_info);
    ioctl(fd,FBIOGET_VSCREENINFO,&fix_info);
    printf("xres = %d,yres = %d, bit = %d\n",var_info.xres,var_info.yres,var_info.bits_per_pixel);
    printf("screen width=%d\n",fix_info.line_length);
    close(fd);
    return 0;
}
