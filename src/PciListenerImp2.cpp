/**
 * File: PciListenerImp2.cpp
 * Description:
 * PciManager library is an easy to use Pin Change Interrupt manager for Arduino.
 *
 * Author: Balazs Kelemen
 * Contact: prampec+arduino@gmail.com
 * Copyright: 2012 Balazs Kelemen
 * Copying permission statement:
    This file is part of PciManager.

    PciManager is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "Arduino.h"
#include "PciListenerImp2.h"
#include <IPciChangeHandler.h>

PciListenerImp2::PciListenerImp2() {
}

void PciListenerImp2::init(byte pin, IPciChangeHandler* handler, bool pullUp) {
  this->pciPin = pin;
  this->_pciChangeHandler = handler;
  
  if(pullUp) {
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }
  this->lastVal = digitalRead(this->pciPin);
}

void PciListenerImp2::pciHandleInterrupt(byte vect) {
  byte val = digitalRead(this->pciPin);
  if(val != this->lastVal) {
    this->lastVal = val;
    this->_pciChangeHandler->pciHandleChange(val, this);
  }
}