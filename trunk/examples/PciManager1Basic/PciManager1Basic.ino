// -- Pin change interrupt
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
