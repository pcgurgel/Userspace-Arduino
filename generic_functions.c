#define SYSFS_PATH "/sys/class/"
#define MAX_BUF 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int sysfs_read(char* path, char* filename)
{
		FILE* fd;
		char buf[MAX_BUF];
		int i;
		char value[MAX_BUF];
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"r");
		fgets(value,10,fd);
		printf("%s",value);
		fclose(fd);

}

int sysfs_write(char* path, char* filename,char* value)
{

		FILE* fd;
		char buf[MAX_BUF];
		int i;
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"w");
		fprintf(fd,"%s",value);
		printf("%s",value);
		fclose(fd);

}
int gpio_export(int gpio_pin)
{
		FILE* fd;
		int i;
		fd=fopen("/sys/class/gpio/export","w");
		fprintf(fd,"%d",gpio_pin);
		fclose(fd);
		return gpio_pin;
}

int gpio_unexport(int gpio_pin)
{
		FILE* fd;
		int i;
		fd=fopen("/sys/class/gpio/unexport","w");
		fprintf(fd,"%d",gpio_pin);
		fclose(fd);
		return gpio_pin;
}
void main()
{
		char ch[MAX_BUF];
		int i;
		//sysfs_read("/sys/class/leds/beaglebone:green:usr0/","brightness");
		//sysfs_write("/sys/class/leds/beaglebone:green:usr0/","brightness","1");
//		gpio_export(14);
		gpio_unexport(14);
}
