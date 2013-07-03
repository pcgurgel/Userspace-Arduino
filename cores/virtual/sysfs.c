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
int sysfs_read(const char* path, const char* filename) 
{
	FILE* fd;
	char buf[MAX_BUF];
	char value[MAX_BUF];
	snprintf(buf, sizeof(buf),"%s%s",path,filename);
	fd=fopen(buf,"r");
        if(!fd)
		return -1;
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
	if(fd < 0) {
		perror("sysfs_write");
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
	fprintf(fd,"%d",gpio_pin);
	fclose(fd);
	return gpio_pin;
}

int gpio_unexport(uint32_t gpio_pin) 
{
	FILE* fd;
	fd=fopen("/sys/class/gpio/unexport","w");
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
