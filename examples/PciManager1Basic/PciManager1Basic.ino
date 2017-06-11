// -- Pin change interrupt
#include <PciManager.h>
#include <PciListenerImp.h>

#define INPUT_PIN 3

void onPinChange(byte changeKind);
PciListenerImp listener(INPUT_PIN, onPinChange);


void setup() {
  Serial.begin(9800);
  PciManager.registerListener(&listener);
  Serial.println("Ready.");
}

void onPinChange(byte changeKind) {
  // -- changeKind can be: CHANGEKIND_HIGH_TO_LOW, or CHANGEKIND_LOW_TO_HIGH HIGH
  Serial.print("pci : ");
  Serial.println(changeKind);
}

void loop() { }
