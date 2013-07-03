/*
  sysfs.h 

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

#ifndef Sysfs_h
#define Sysfs_h
#include <inttypes.h>
#ifdef __cplusplus
extern "C"{
#endif

#define MAX_BUF 64

int sysfs_read(const char* , const char*);
int sysfs_write(const char*, const char* , int);
int gpio_export(uint32_t);
int gpio_unexport(uint32_t);
void delay(unsigned long);
void delayMicroseconds(unsigned int);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
