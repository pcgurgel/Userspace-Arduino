/*
  wiring_digital.c - digital input and output functions
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

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

  Modified 28 September 2010 by Mark Sproul

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/

#include "wiring_digital.h"
#include "Arduino.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


void pinMode(uint8_t pin, uint8_t mode)
{
	int fd;
	char buf[4];

	if(g_APinDescription[pin].pinType == GPIO) {

		snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", g_APinDescription[pin].gpioPin);
		fd = open(buf, O_WRONLY);
		if (fd < 0) {
			perror("pinMode");
			return;
		}
		if (mode == 1)
			write(fd, "out", 4);
		else
			write(fd, "in", 3);

		close(fd);
	} else {
		printf("Pin %d is not configured as GPIO!/n", pin);
		return;
	}
}


void digitalWrite(uint8_t pin, uint8_t val)
{

	int fd;
	char buf[4];
	if(g_APinDescription[pin].pinType == GPIO) {
		snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", g_APinDescription[pin].gpioPin);

		fd = open(buf, O_WRONLY);
		if (fd < 0) {
			perror("digitalWrite");
			return;
		}
		if (val==0)
			write(fd, "0", 2);
		else
			write(fd, "1", 2);

		close(fd);
	} else {
		printf("Pin %d is not configured as GPIO!/n", pin);
		return;
	}

#if 0
if (pin==14) {
    int xkbmajor = XkbMajorVersion, xkbminor = XkbMinorVersion;
    int xkbopcode, xkbevent, xkberror;
    Atom ledatom;
    const char *led="Scroll Lock";
    Display *dpy = XOpenDisplay(0);

    if (XkbQueryExtension(dpy, &xkbopcode, &xkbevent, &xkberror,
			  &xkbmajor, &xkbminor)) {
	ledatom = XInternAtom(dpy, led, True);
	if ((ledatom != None) &&
	    XkbGetNamedIndicator(dpy, ledatom, NULL, NULL, NULL, NULL)) {
	    if (XkbSetNamedIndicator(dpy, ledatom, True,
				     val ? LedModeOn : LedModeOff, False, NULL) == False) {
		printf("Failed to set led named %s\n",led);
	    }
	} else {
	    printf("Invalid led name: %s\n", led);
	}
    } else {
	printf("  Server does not have the XKB Extension\n");
    }

    XFlush(dpy);
    XCloseDisplay(dpy);
}
#endif

}

int digitalRead(uint8_t pin)
{
	int fd;
	char buf[4];
	char ch;
	int value;
	if(g_APinDescription[pin].pinType == GPIO) {

		snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", g_APinDescription[pin].gpioPin);

		fd = open(buf, O_RDONLY);
		if (fd < 0) {
			perror("digitalRead");
			return -1;
		}

		read(fd, &ch, 1);

		if (ch != '0') {
			value = 1;
		} else {
			value = 0;
		}

		close(fd);
		return value;
	} else {
		printf("Pin %d is not configured as GPIO!/n", pin);
		return -1;
	}

}

int export_gpio(uint32_t pin)
{
	int fd, len;
	char buf[4];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pin);
	printf("Writing to gpio/export: %d\n", pin);
	write(fd, buf, len);
	close(fd);

	return 0;
}
