#include "sensors.h"

int AnalogSensorsData[8];
int DigitalSensorsData[8];

int HT = 900;
int LT = 300;

int T = (HT + LT) / 2;

#define out A0

#define S1 2
#define S2 3
#define S3 4

void SensorsRead() {
  for (int i = 0; i <= 7; i++) {

    digitalWrite(S1, (i % 2));
    digitalWrite(S2, (int(i / 2) % 2));
    digitalWrite(S3, (int(int(i / 2) / 2)));

    AnalogSensorsData[i] = analogRead(out);

    if (AnalogSensorsData[i] > T) {
      DigitalSensorsData[i] = 1;
    }

    else if (AnalogSensorsData[i] < T) {
      DigitalSensorsData[i] = 0;
    }
  }
  for (int i = 0; i <= 7; i++) {
    Serial.print(AnalogSensorsData[i]);
    Serial.print(" | ");
    Serial.print(DigitalSensorsData[i]);
    Serial.print("    ");
  }
  Serial.println(" ");
}
