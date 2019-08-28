/*
  MAX17043 Lithium Cell Fuel Gauge over I2C using integer calculations.
  MAX17043.h Copyright (C) 2019 Ewan Parker.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

  The author may be reached at https://www.ewan.cc/ for queries.
*/

#ifndef _Max17043_H
#define _Max17043_H

// STM32 GPIO pins.
#ifdef ARDUINO_ARCH_STM32F1
#endif
#define MAX17043_PWR_INT PB1

// Espressif ESP32 GPIO pins.
#ifdef ARDUINO_ARCH_ESP32
#define MAX17043_I2C_SDA 33
#define MAX17043_I2C_SCL 32
#define MAX17043_I2C_BPS 100000
#define MAX17043_PWR_INT 35
#endif

// Microchip AVR and other Arduino GPIO pins.
#ifndef MAX17043_PWR_INT
#define MAX17043_PWR_INT 2
#endif

#include <Arduino.h>

class MAX17043
{
  public:
    MAX17043();

    uint16_t cellVoltage();  // Return the cell's voltage in mV.
    uint8_t stateOfCharge(); // Return the charge percentage.
    uint16_t version();      // Show manufacturer's version.
};

#endif /* _Max17043_H */
