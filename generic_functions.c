#define SYSFS_PATH "/sys/class/"
#define MAX_BUF 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int sysfs_read(const char* path, const char* filename) 
{
		FILE* fd;
		char buf[MAX_BUF];
		char value[MAX_BUF];
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"r");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}

		fgets(value,10,fd);
		fclose(fd);
        return 0;
}

int sysfs_write(const char* path, const char* filename,int value) 
{
		FILE* fd;
		char buf[MAX_BUF];
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"w");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}
		fprintf(fd,"%d",value);
		fclose(fd);
		return 0;
}
int gpio_export(uint32_t gpio_pin) 
{
		FILE* fd;
		fd=fopen("/sys/class/gpio/export","w");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}

		fprintf(fd,"%d",gpio_pin);
		fclose(fd);
		return gpio_pin;
}

int gpio_unexport(uint32_t gpio_pin) 
{
		FILE* fd;
		fd=fopen("/sys/class/gpio/unexport","w");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}
		fprintf(fd,"%d",gpio_pin);
		fclose(fd);
		return gpio_pin;
}

void delay(unsigned long ms)
{
		usleep(ms*1000);
}

void delayMicroseconds(unsigned int us)
{
		usleep(us);
}
int gpio_setdirection(uint32_t gpio_pin, const char* direction)
{
		FILE* fd;
		fd=fopen("/sys/class/gpio/unexport","w");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}
		
		fclose(fd);
		return gpio_pin;
}

int main()
{

}
