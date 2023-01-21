#include <Arduino.h>

#define PIN_SENSOR_PH A1
// bagian ini yang perlu diatur
#define PH4 3.1 // berapa tegangan ketika ph 4?
#define PH7 2.6 // berapa tergangan ketika ph 7?

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_SENSOR_PH, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  float phValue = analogRead(PIN_SENSOR_PH) ;
  float voltage = phValue * (5.0 / 1023.0);
  float phStep  = (PH4 - PH7) / 3;
  float pO      = 7.00 + ((PH7 - voltage) / phStep);

  Serial.print("Voltage : ");
  Serial.print(voltage);
  Serial.print(" -- PH : ");
  Serial.println(pO);

  delay(500);
}
