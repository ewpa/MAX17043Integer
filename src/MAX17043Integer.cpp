/*
  MAX17043 Lithium Cell Fuel Gauge over I2C using integer calculations.
  MAX17043Integer.cpp Copyright (C) 2019 Ewan Parker.

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

#include "MAX17043Integer.h"
#include "MAX17043IntegerPrivate.h"
#include <Wire.h>

// Constructor.
MAX17043Integer::MAX17043Integer()
{
  #ifdef ARDUINO_ARCH_ESP32
  Wire.begin(33, 32, 100000);
  #else
  Wire.begin();
  #endif
}

// Read a 16 bit register.
uint16_t _readReg16(uint8_t reg)
{
  Wire.beginTransmission(MAX17043_I2C_ADDR);
  Wire.write((uint8_t)reg);
  Wire.endTransmission();

  uint8_t msb, lsb;
  Wire.requestFrom((uint8_t)MAX17043_I2C_ADDR, (uint8_t)2);
  msb = Wire.read();
  lsb = Wire.read();
  return (msb << 8) + lsb;
}

// Read and return the cell voltage in millivolts.
uint16_t MAX17043Integer::cellVoltage()
{
  return 1.25 * (_readReg16(MAX17043_REG_VCELL) >> 4);
}

// Read and return the percentage state of charge.
uint8_t MAX17043Integer::stateOfCharge()
{
  return _readReg16(MAX17043_REG_SOC) >> 8;
}

// Manufacturer's version.
uint16_t MAX17043Integer::version()
{
  return _readReg16(MAX17043_REG_VERSION);
}
