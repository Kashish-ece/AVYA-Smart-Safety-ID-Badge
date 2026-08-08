#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int buttonPin = 13;  // ✅ You matched the working test pin
bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  
  if (SerialBT.begin("SOS_Device")) {
    Serial.println("Bluetooth ready to pair");
  } else {
    Serial.println("Bluetooth failed to start");
  }
  Serial.println("Bluetooth started. Waiting for connection...");
}
void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !buttonPressed) {
    SerialBT.println("SOS");  // ensure println adds newline
    Serial.println("SOS sent via Bluetooth");
    buttonPressed = true;
    delay(1000); // 1 second delay to debounce better
  }

  if (buttonState == HIGH) {
    buttonPressed = false;
  }

  delay(100);  // keep this small
}
