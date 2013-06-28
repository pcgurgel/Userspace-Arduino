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
		int value;
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"r");
		fscanf(fd,"%d",&value);
		fclose(fd);
		return value;
}

int sysfs_write(char* path, char* filename,int value)
{

		FILE* fd;
		char buf[MAX_BUF];
		int i;
		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"w");
		fprintf(fd,"%d",value);
		fclose(fd);

}

void main()
{
		char ch[MAX_BUF];
		int i;
		//printf("%d",sysfs_read("/sys/class/leds/beaglebone:green:usr0/","brightness"));
		sysfs_write("/sys/class/leds/beaglebone:green:usr0/","brightness",1);
}
