/*
  MAX17043 Lithium Cell Fuel Gauge over I2C using integer calculations.
  MAX17043.cpp Copyright (C) 2019 Ewan Parker.

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

#include "MAX17043.h"
#include "defs/MAX17043_Address.h"
#include "defs/MAX17043_Registers.h"
#include <Wire.h>

// Constructor.
MAX17043::MAX17043()
{
  #ifdef MAX17043_I2C_SDA
  Wire.begin(MAX17043_I2C_SDA, MAX17043_I2C_SCL, MAX17043_I2C_BPS);
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

// Write a 16 bit register.
void _writeReg16(uint8_t reg, uint16_t val)
{
  Wire.beginTransmission(MAX17043_I2C_ADDR);
  Wire.write((uint8_t)reg);
  Wire.write((uint8_t)(val >> 8));   // MSB.
  Wire.write((uint8_t)(val & 0xFF)); // LSB.
  Wire.endTransmission();
}

// Read and return the cell voltage in millivolts.
uint16_t MAX17043::cellVoltage()
{
  return 1.25 * (_readReg16(MAX17043_REG_VCELL) >> 4);
}

// Read and return the percentage state of charge.
uint8_t MAX17043::stateOfCharge()
{
  return _readReg16(MAX17043_REG_SOC) >> 8;
}

// Manufacturer's version.
uint16_t MAX17043::version()
{
  return _readReg16(MAX17043_REG_VERSION);
}

// Set the charge percentage (or lower) for trigger, ranging from 1 to 32%.
void MAX17043::setAlertPercent(uint8_t pct)
{
  if (pct < 1) pct = 1; else if (pct > 32) pct = 32;
  uint16_t config = _readReg16(MAX17043_REG_CONFIG);
  // ATHD is 2's complement and 5 bits.
  uint8_t athd = pct - 1;
  athd ^= 0xFF;
  config &= (0xFFFF - 0x001F);
  config |= (athd & 0x1F);
  _writeReg16(MAX17043_REG_CONFIG, config);
}

// Report low power alert flag state.
bool MAX17043::getAlertStatus()
{
  uint16_t config = _readReg16(MAX17043_REG_CONFIG);
  return (config & 0x20) != 0x00;
}

// Clear low power alert flag.
void MAX17043::clearAlertStatus()
{
  uint16_t config = _readReg16(MAX17043_REG_CONFIG);
  config &= (0xFFFF - 0x0020);
  _writeReg16(MAX17043_REG_CONFIG, config);
}
