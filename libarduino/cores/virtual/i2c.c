/*
 * i2c.c - the i2c library
 *
 * Copyright (c) 2013 Parav Nagarsheth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 */

#include <i2c.h>
#include <dirent.h>
#include <linux/i2c-dev.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define MAX_BUF 100

int i2c_getadapter(uint32_t i2c_bus_address)
{
	char buf[MAX_BUF];
	DIR *d;
	struct dirent *dir;
	int adapter_nr = -1;
	snprintf(buf, sizeof(buf), "/sys/devices/ocp.2/%x.i2c", i2c_bus_address);
	d = opendir(buf);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			if (!strncmp("i2c", dir->d_name,3)) {
				sscanf(dir->d_name, "i2c-%d", &adapter_nr);
				closedir(d);
				return adapter_nr;
			}
		}
		closedir(d);
	}
	return -1;
}

int i2c_openadapter(uint8_t i2c_adapter_nr)
{
	char buf[MAX_BUF];
	int i2c_fd;
	snprintf(buf, sizeof(buf), "/dev/i2c-%d", i2c_adapter_nr);
	if ((i2c_fd = open(buf, O_RDWR)) < 1) {
		perror("Failed to open adapter");
		return -1;
	}
	return i2c_fd;
}

int i2c_setslave(int i2c_fd, uint8_t addr)
{
	if (ioctl(i2c_fd, I2C_SLAVE, addr) < 0) {
		fprintf(stderr, "Failed to set slave address %d:", addr);		
		perror("");
		return -1;	
	}
	return 0;
}

