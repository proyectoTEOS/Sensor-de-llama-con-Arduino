/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

const int sensorPinT = A0;
int valT, calibrationReadingT;
const long intervalT = 250;
unsigned long previousMillisT = 0;
String resultSerialT;

void setup() {
  Serial.begin(9600);
  Serial.print("Iniciando calibracion");
  do {
    valT = 0;
    for (int iT = 0; iT < 30; iT++) {
      valT += analogRead(sensorPinT);
      unsigned long currentMillisT = millis();
      if (currentMillisT - previousMillisT >= intervalT) {
        previousMillisT = currentMillisT;
        Serial.print(" * ");
      }
      delay(33);
    }
    calibrationReadingT = valT / 30;
  } while ((calibrationReadingT) < analogRead(sensorPinT));
  Serial.println("Calibracion finalizada");
}

void loop() {
  valT = analogRead(sensorPinT);
  valT = map(valT, 0, calibrationReadingT, 100, 0);
  valT = constrain (valT, 0, 100);
  resultSerialT = "Hay un " + String(valT) + " % de flama";
  Serial.println(resultSerialT);
  delay(1000);
}
