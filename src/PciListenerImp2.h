/**
 * File: PciListenerImp2.h
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

#ifndef PCI_LISTENERIMP2_H
#define PCI_LISTENERIMP2_H

#include <Arduino.h>
#include <PciListener.h>

class IPciChangeHandler;

/**
 * An extended PinChangeInterrupt listener implementation.
 * The difference between this, and PciListenerImpl, is that this also passes the listener instance to the handler on event.
 */
class PciListenerImp2 : public PciListener
{
  public:
    PciListenerImp2();
    /**
     * Initialize the listener.
     *  - pin - Pin to listen
     *  - handler - Handler
     *  - puppUp - Set true, to have the pin set in pullup mode.
     */
    void init(byte pin, IPciChangeHandler* handler, bool pullUp = false);
    virtual void pciHandleInterrupt(byte vector);
    byte lastVal;
  private:
    IPciChangeHandler* _pciChangeHandler;
};

#endif

