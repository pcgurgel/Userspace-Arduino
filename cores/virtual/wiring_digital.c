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

#include <inttypes.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

void pinMode(uint8_t pin, uint8_t mode)
{
printf("pinMode() called with pin=%d and mode=%d\n",pin,mode);
}

static void turnOffPWM(uint8_t timer)
{
printf("turnOffPWM() called!\n");
}

void digitalWrite(uint8_t pin, uint8_t val)
{
printf("digitalWrite() called with pin=%d and val=%d\n",pin,val);
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
	printf("digitalRead() called for pin=%d and returning 0\n",pin);
	return 0;
}
