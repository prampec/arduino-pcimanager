/**
 * File: IPciHandler.h
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

#ifndef PCI_IPCICHANGEHANDLER_H
#define PCI_IPCICHANGEHANDLER_H

#include <Arduino.h>

/**
 * PinChangeInterrupt listener abstract class. Please override this class with a custom pciHandleInterrupt() callback
 * to be used in PciListenerImpl2.
 */
class IPciChangeHandler {
  public:
    /**
     * This method will be called by the PciManager on pin change. The function will be fired only when to corresponding pin
     * was changed. See PciListenerImpl2 for details.
     */
    virtual void pciHandleChange(byte changedTo, PciListenerImp2* listener);
};

#endif

