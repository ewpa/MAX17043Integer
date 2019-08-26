/*
  MAX17043 Lithium Cell Fuel Gauge over I2C using integer calculations.
  MAX17043Integer.h Copyright (C) 2019 Ewan Parker.

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

#ifndef _Max17043Integer_H
#define _Max17043Integer_H

#include <Arduino.h>

class MAX17043Integer
{
  public:
    MAX17043Integer();

    uint16_t cellVoltage();  // Return the cell's voltage in mV.
    uint8_t stateOfCharge(); // Return the charge percentage.
    uint16_t version();      // Show manufacturer's version.
};

#endif /* _Max17043Integer_H */
