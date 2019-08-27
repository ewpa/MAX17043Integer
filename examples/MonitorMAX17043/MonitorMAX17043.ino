/*
  Test drive of MAX17043 Lithium Fuel Cell Gauge integer library.
  MonitorMAX17043.ino Copyright (C) 2019 Ewan Parker.

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

// Create an instance of the MAX17043 fuel gauge.
MAX17043 gauge;

// Output stream.
#ifdef ARDUINO_ARCH_AVR
HardwareSerial *s;
#define SERIAL_BAUD 9600
#endif
#ifdef ARDUINO_ARCH_STM32F1
USBSerial *s;
#define SERIAL_BAUD 9600
#endif
#ifdef ARDUINO_ARCH_ESP32
HardwareSerial *s;
#define SERIAL_BAUD 115200
#endif

void info() {
  s->println(); s->println();
  s->println("Interrogate an I2C attached MAX17043 Lithium Cell Fuel Gauge.");
  s->println("Ewan Parker 26th August 2019.");
}

void cellVoltage()
{
  uint16_t mV = gauge.cellVoltage();
  s->print("Voltage (mV): "); s->println(mV);
}

void stateOfCharge()
{
  uint8_t soc = gauge.stateOfCharge();
  s->print("State of Charge (%): "); s->println(soc);
}

void version()
{
  uint16_t ver = gauge.version();
  s->print("Version: "); s->println(ver);
}

void setup()
{
  s = &Serial;
  s->begin(SERIAL_BAUD);
  // Show program and chip information.
  info();
}

void loop() {
  s->println();
  // Show options.
  s->print("[?] [V]oltage [S]tate% > ");
  while (! s->available()) {}
  // Wait for a character to be typed, then process the required action.
  char in = s->read(); if (in >= 'a' && in <= 'z') in += ('A' - 'a');
  switch (in) {
    case '?' : s->println("[?] Info"); info(); break;
    case 'V' : s->println("Cell [V]oltage"); cellVoltage(); break;
    case 'S' : s->println("Percent [S]tate of Charge"); stateOfCharge(); break;
    case 'I' : s->println("Chip Vers[I]on"); version(); break;
    default  : s->println("[HELP]");
               s->println();
               s->println("[?]: Program and Chip information.");
               s->println("[V]: Read the cell's voltage.");
               s->println("[S]: Calculate cell's charge state percentage.");
               s->println("[I]: Show manufacturer's version number.");
               break;
  }
}
