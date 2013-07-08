/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_BEAGLEBONE_
#define _VARIANT_BEAGLEBONE_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/


#ifdef __cplusplus
//#include "UARTClass.h"
//#include "USARTClass.h"
#endif

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (25u)

/* Mapping pins to pin numbers in userspace */

//Header Pins
//#define P8_01  DGND
//#define P8_02  DGND
#define P8_03 (6u)
#define P8_04 (7u)
#define P8_05 (2u)
#define P8_06 (3u)
#define P8_07 (36u)  
#define P8_08 (37u) 
#define P8_09 (39u)
#define P8_10 (38u)
#define P8_11 (13u)
#define P8_12 (12u)
#define P8_13 (9u)
#define P8_14 (10u)
#define P8_15 (15u)
#define P8_16 (14u)
#define P8_17 (11u)
#define P8_18 (35u)
#define P8_19 (8u)
#define P8_20 (33u)
#define P8_21 (32u)
#define P8_22 (5u)
#define P8_23 (4u)
#define P8_24 (1u)
#define P8_25 (0u)
#define P8_26 (31u)
#define P8_27 (56u)
#define P8_28 (58u)
#define P8_29 (57u)
#define P8_30 (59u)
#define P8_31 (54u)
#define P8_32 (55u)
#define P8_33 (53u)
#define P8_34 (51u)
#define P8_35 (52u)
#define P8_36 (50u)
#define P8_37 (48u)
#define P8_38 (49u)
#define P8_39 (46u)
#define P8_40 (47u)
#define P8_41 (44u)
#define P8_42 (45u)
#define P8_43 (42u)
#define P8_44 (43u)
#define P8_45 (40u)
#define P8_46 (41u)

//#define P9_01 GND
//#define P9_02 GND
//#define P9_03 3_3V
//#define P9_04 3_3V 
//#define P9_05 VDD_5V
//#define P9_06 VDD_5V
//#define P9_07 SYS_5V  
//#define P9_08 SYS_5V 
//#define P9_09 PWR_BUT
//#define P9_10 SYS_RSTn
#define P9_11 (28u)
#define P9_12 (30u)
#define P9_13 (29u)
#define P9_14 (18u)
#define P9_15 (16u)
#define P9_16 (19u)
#define P9_17 (87u)
#define P9_18 (86u)
#define P9_19 (95u)
#define P9_20 (94u)
#define P9_21 (85u)
#define P9_22 (84u)
#define P9_23 (17u)
#define P9_24 (97u)
#define P9_25 (107u)
#define P9_26 (96u)
#define P9_27 (105u)
#define P9_28 (103u)
#define P9_29 (101u)
#define P9_30 (102u)
#define P9_31 (100u)
//#define P9_32 VADC
#define P9_33 AIN4
//#define P9_34 AGND
#define P9_35 AIN6
#define P9_36 AIN5
#define P9_37 AIN2
#define P9_38 AIN3
#define P9_39 AIN0
#define P9_40 AIN1
#define P9_41A (109u)
//#define P9_41B GPIO3_20
#define P9_42A (89u)
//#define P9_42B (u)
//#define P9_43 GND
//#define P9_44 GND
//#define P9_45 GND
//#define P9_46 GND

//USR LEDs
#define USR0  (21u) 
#define USR1  (22u)
#define USR2  (23u)
#define USR3  (24u)

/*
 * Analog Pins
 */
#define AIN0 (0xffff) // temporarily assign an unallocated value 
#define AIN1 (0xfffe)
#define AIN2 (0xfffd)
#define AIN3 (0xfffc)
#define AIN4 (0xfffb)
#define AIN5 (0xfffa)
#define AIN6 (0xfff9)

#define ANALOG_PIN (0xffff)


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
/*
 * Arduino Pin     |  BBB    Header Pin  | Label
 * ----------------+---------------------+-------
 *   0             |  P9_11              |
 *   1             |  P9_13              |
 *   2             |  P9_15              |
 *   3             |  P9_14              |
 *   4             |  P9_12              |
 *
 *   5             |  P9_16              |
 *   6             |  P9_42A             |
 *   7             |  P8_19              |
 *   8             |  P9_19              |
 *   9             |  P9_20              |
 *  10             |  P9_17              |
 *
 *  11             |  P9_18              |
 *  12             |  P9_21              |
 *  13             |  P9_22              |
 *  14             |  USR0               |
 *  15             |  USR1               |
 *  16             |  USR2               |
 *  17             |  USR3               |
 *  18             |  P9_33              |
 *  19             |  P9_35              |
 *  20             |  P9_36              |
 *  21             |  P9_37              |
 *  22             |  P9_38              |
 *  23             |  P9_38              |
 *  24             |  P9_40              |
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
PinDescription g_APinDescription[]=
{
  // The offsets can be derived from userspace pin numbers defined in the header file
  // 0 .. 13 - Digital pins
  // ----------------------
  // 0/1 - UART (Serial)
  { P9_11,   30,  UART }, // URXD
  { P9_13,   31,  UART }, // UTXD

  // 2
  { P9_15,   48,  GPIO }, // PIN2
  { P9_14,   31,  PWM  }, // PWM1A
  { P9_12,   60,  GPIO }, // PIN4

  // 5
  { P9_16,   51,  PWM  }, // PWM1B
  { P9_42A,   7,  PWM  }, // PWM0
  { P8_19,   19,  PWM  }, // PWM2A

  //8
  { P9_19,   13,  I2C  }, // I2C2_SCL
  { P9_20,   12,  I2C  }, // I2C2_SDA
  
  // 10
  { P9_17,    5,  SPI  }, // SPI0_CSO
  { P9_18,    4,  SPI  }, // MOSI
  { P9_21,    3,  SPI  }, // MISO
  { P9_22,    2,  SPI  }, // SCK
  
  // 14 .. 17 - USR LEDs
  { USR0,    53,  LED  },
  { USR1,    86,  LED  },
  { USR2,    87,  LED  },
  { USR3,    88,  LED  },

  // 18 .. 24 - Analog pins
  // ----------------------
  { AIN4,  ANALOG_PIN,  ANALOG  },
  { AIN6,  ANALOG_PIN,  ANALOG  },
  { AIN5,  ANALOG_PIN,  ANALOG  },
  { AIN2,  ANALOG_PIN,  ANALOG  },
  { AIN3,  ANALOG_PIN,  ANALOG  },
  { AIN0,  ANALOG_PIN,  ANALOG  },
  { AIN1,  ANALOG_PIN,  ANALOG  }
} ;

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

void init( void )
{
unsigned int i=0;
  /* Derive the offsets and export the GPIOs */
  for (i = 0; i < PINS_COUNT; i += 1) {
	if(g_APinDescription[i].pinType != ANALOG)
		g_APinDescription[i].pinOffset = g_APinDescription[i].headerPin * 4;
	if(g_APinDescription[i].pinType == GPIO)
		gpio_export(g_APinDescription[i].gpioPin);
  }
}

#ifdef __cplusplus
}
#endif

#endif /* _VARIANT_BEAGLEBONE_ */
