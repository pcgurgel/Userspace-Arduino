/*
  sysfs.c 

  Copyright (c) 2013 Anuj Deshpande

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id$
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "sysfs.h"
#include <time.h>

char* sysfs_read(const char* path, const char* filename)
{
		FILE* fd;
		char buf[MAX_BUF];
		char* temp;
		char value[MAX_BUF];

		snprintf(buf, sizeof(buf),"%s%s",path,filename);
		fd=fopen(buf,"r");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}
		fscanf(fd,"%s",value);
		fclose(fd);
		temp = (char*)malloc(strlen(value));
		strcpy(temp,value);
		printf("%s\n",value);
        return temp;
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
				printf("\nFile already open");
				return gpio_pin;//file already open
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
		char buf[MAX_BUF];
		snprintf(buf, sizeof(buf),"/sys/class/gpio/gpio%d/direction",gpio_pin);
		fd=fopen(buf,"w");
		if(fd==NULL){
				printf("\nError opening file");
				return -1;
		}
		fprintf(fd,"%s",direction);
		fclose(fd);
		return gpio_pin;
}
