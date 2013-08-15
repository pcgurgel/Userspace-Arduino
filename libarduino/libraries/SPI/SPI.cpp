/*
 * Copyright (c) 2013 by Anuj Deshpande <anujdeshpande92@gmail.com>
 * SPI Library for Userspace Arduino
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "SPI.h"

#define LSBFIRST 0
#define MSBFIRST 1

SPIClass SPI;
SPIClass::SPIClass() {
  tr.len = 1;
  tr.speed_hz = 4000000 ; // default set to 4 Mhz
  tr.bits_per_word = 8;
  device="/dev/spidev0.0";
}
void SPIClass::begin(){

  fd=open(device,O_RDWR);
  ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  if (ret == -1)
	perror("SPI_IOC_WR_BITS_PER_WORD not set");
}

char SPIClass::transfer(char data) {
  ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
  if (ret < 1)
	perror("SPI_IOC_MESSAGE not sent");

}
void SPIClass::setBitOrder(uint8_t bOrder){
  if(bOrder == LSBFIRST) {
	bitOrder=LSBFIRST;
  }
  else {
	bitOrder=MSBFIRST;
  }
}

void SPIClass::setDataMode(uint8_t mode) {
  ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1)
	perror(o"SPI_IOC_WR_MODE not set");
}

void SPIClass::setClockDivider(uint8_t rate) {
  ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
  if (ret == -1)
	perror("SPI_IOC_WR_MAX_SPEED_HZ not set");
}

void SPIClass::end() {
  close(fd);
}
