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
