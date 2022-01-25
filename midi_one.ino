int analogPin1 = 0;
int analogPin2 = 1;

int midiController1 = 16; // general purpose controller 1
int midiController2 = 17; // general purpose controller 2
int midiChannel = 1;

int threshold = 4;

int delayMs = 10;

void setup() {
  // baud rate for USB serial
  Serial.begin(38400);
}

int value1; // potentiometer value / 1024
int value2;

void loop() {
  int newValue1 = analogRead(analogPin1);
  int newValue2 = analogRead(analogPin2);

  // only update if over noise threshold
  if (abs(value1 - newValue1) > threshold) {
    value1 = newValue1;
    int normalisedVal1 = value1 / 8; // MIDI value / 128

    Serial.print("A0 is: ");
    Serial.println(normalisedVal);

    usbMIDI.sendControlChange(midiController1, normalisedVal1, channel);
  }

  if (abs(value2 - newValue2) > threshold) {
    value2 = newValue2;
    int normalisedVal2 = value2 / 8; // MIDI value / 128

    Serial.print("A0 is: ");
    Serial.println(normalisedVal);

    usbMIDI.sendControlChange(midiController2, normalisedVal2, channel);
  }

  delay(delayMs);
}
