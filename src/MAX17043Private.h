/*
  MAX17043 Lithium Cell Fuel Gauge over I2C using integer calculations.
  MAX17043Private.h Copyright (C) 2019 Ewan Parker.

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

#ifndef _Max17043Private_H
#define _Max17043Private_H

#define MAX17043_I2C_ADDR 0x36

#define MAX17043_REG_VCELL    0x02
#define MAX17043_REG_SOC      0x04
#define MAX17043_REG_VERSION  0x08

#endif /* _Max17043Private_H */
