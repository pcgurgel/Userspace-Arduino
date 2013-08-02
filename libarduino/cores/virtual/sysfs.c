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

*/
#include "sysfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int sysfs_read(const char *path, const char *filename, char *value)
{
	FILE *fd;
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), "%s%s", path, filename);
	fd = fopen(buf, "r");
	if (fd == NULL) {
		printf("\nsysfs_read: Error opening file %s", buf);
		return -1;
	}
	fscanf(fd, "%s", value);
	fclose(fd);
	return 0;
}

int sysfs_write(const char *path, const char *filename, int value)
{
	FILE *fd;
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), "%s%s", path, filename);
	fd = fopen(buf, "w");
	if (fd == NULL) {
		printf("\nsysfs_write: Error opening file %s", buf);
		return -1;
	}
	fprintf(fd, "%d", value);
	fclose(fd);
	return 0;
}

void sysfs_gpio_setvalue(uint8_t pin, uint8_t value)
{
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/", pin);
	sysfs_write(buf, "value", value);
}

int sysfs_gpio_getvalue(uint8_t pin)
{
	char buf[MAX_BUF], value[4];
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/", pin);
	sysfs_read(buf, "value", value);
	return atoi(value);
}

/* sysfs_adc_getvalue
 * Gets a value from the sysfs adc entries
 * Returns a value on the scale of (0 to 4095)
 */
uint32_t sysfs_adc_getvalue(uint32_t channel)
{
	char buf[MAX_BUF], channelname[20], value[8];
	snprintf(buf, sizeof(buf), SYSFS_ADC_DIR"/");
	snprintf(channelname, sizeof(channelname), "in_voltage%d_raw", channel);
	sysfs_read(buf, channelname, value);
	return atol(value);
}

void sysfs_led_setvalue(uint8_t led, uint8_t value)
{
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), SYSFS_LED_DIR "/beaglebone:green:usr%d/", led);
	sysfs_write(buf, "brightness", value);
}

int gpio_export(uint32_t gpio_pin)
{
	FILE *fd;
	fd = fopen("/sys/class/gpio/export", "w");
	if (fd == NULL) {
		printf("\ngpio_export: File already open");
		return gpio_pin;
	}

	fprintf(fd, "%d", gpio_pin);
	fclose(fd);
	return gpio_pin;
}

int gpio_unexport(uint32_t gpio_pin)
{
	FILE *fd;
	fd = fopen("/sys/class/gpio/unexport", "w");
	if (fd == NULL) {
		printf("\ngpio_unexport: Error opening file");
		return -1;
	}
	fprintf(fd, "%d", gpio_pin);
	fclose(fd);
	return gpio_pin;
}

int gpio_setdirection(uint32_t gpio_pin, const char *direction)
{
	FILE *fd;
	char buf[MAX_BUF];
	snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio_pin);
	fd = fopen(buf, "w");
	if (fd == NULL) {
		printf("\ngpio_setdirection: Error opening file %s", buf);
		return -1;
	}
	fprintf(fd, "%s", direction);
	fclose(fd);
	return gpio_pin;
}

int pwm_export(uint32_t pwm_pin)
{
	FILE *fd;
	fd = fopen("/sys/class/pwm/export", "w");
	if (fd == NULL) {
		printf("\npwm_export: Error opening file");
		return -1;
	}
	switch (pwm_pin) {
	case 31:
			fprintf(fd, "1");
			break;
	case 51:
			fprintf(fd, "2");
			break;
	case 7:
			fprintf(fd, "0");
			break;
	}
	fclose(fd);
	return pwm_pin;
}
