# Introduction #

With PciManager Arduino library you can manage the Pin Change Interrupt of the microcontroller.
You can register listeners in the PciManager for a change of a pin. The manager handles the interrupt and calls the listeners.

PciManager does not read the value of the pin, it just hides dirty hardware flags, but flexible enough to use multiply listeners on multiply pins.

__NOTE__: On some hardware the pin change interrupt is not implemented by interrupt vectors. As PciManager operates with interrupt vectors, it will just not do the job on hardware like this.


# Example code #

```
#include <PciManager.h>
#include <PciListenerImp.h>

#define INPUT_PIN 3

PciListenerImp listener(INPUT_PIN, onPinChange);


void setup() {
  Serial.begin(9800);
  PciManager.registerListener(INPUT_PIN, &listener);
  Serial.println("Ready.");
}

void onPinChange(byte changeKind) {
  Serial.print("pci : ");
  Serial.println(changeKind);
}

void loop() { }
```
