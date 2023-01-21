// #include <Arduino.h>
// #include <DallasTemperature.h>

// // pin analog sensor dihubungkan pada Analog
// #define PIN_SENSOR_SUHU A0

// // Setup a oneWire instance to communicate with any OneWire devices
// OneWire oneWire(PIN_SENSOR_SUHU);

// // Pass our oneWire reference to Dallas Temperature sensor
// DallasTemperature sensors(&oneWire);

// void setup(void)
// {
//   // Start serial communication for debugging purposes
//   Serial.begin(9600);
//   // Start up the library
//   sensors.begin();
// }

// void loop(void)
// {
//   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
//   sensors.requestTemperatures();
//   Serial.print("Celsius : ");
//   Serial.println(sensors.getTempCByIndex(00));

//   delay(500);
// }