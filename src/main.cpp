#include <Arduino.h>

#include <DallasTemperature.h>
#include <OneWire.h>

// pin data sensor yang dihubungkan pada pin Analog
#define PIN_SENSOR_SUHU A0
#define PIN_SENSOR_PH A1

// Setup oneWire instance to communicate with any OneWire devices
OneWire oneWire(PIN_SENSOR_SUHU);
DallasTemperature suhu(&oneWire);

// bagian ini yang perlu diatur jika ingin kalibrasi
/*
jika ingin kalibrasi PH ubah bool kalibrasi = true;
jika tidak kalibrasi ubah    bool kalibrasi = false;
*/
bool kalibrasi = false;
#define PH4 3.0 // berapa tegangan ketika ph 4? 3.0
#define PH7 2.6 // berapa tergangan ketika ph 7? 2.6

// setup program => hanya akan berjalan sekali saja ketika baru dijalankan
void setup()
{
  // insisiasi PIN_SENSOR_PH sebagai input
  pinMode(PIN_SENSOR_PH, INPUT);
  // inisiasi serial monitor untuk melihat output program
  Serial.begin(9600);
  // inisiasi sensor suhu
  suhu.begin();
}

// program yang akan berjalan selalu
void loop()
{
  if (!kalibrasi){
    // baca sensor PH
    float phValue = analogRead(PIN_SENSOR_PH);        // baca nilai pin A0
    float voltage = phValue * (5.0 / 1023.0);         // ubah nilainya menjadi tegangan
    float phStep  = (PH4 - PH7) / 3;                  // dapatkan nilai phStep => (PH4 - PH7) / (7 - 4)
    float pO      = 7.00 + ((PH7 - voltage) / phStep);// dapatkan nilai PH asli

    // baca sensor suhu
    suhu.requestTemperatures();
    // tampilkan nilai sensor suhu
    Serial.print("Suhu : ");
    Serial.print(suhu.getTempCByIndex(00));
    Serial.print(" C");

    // tampilkan nilai sensor PH
    Serial.print(" | PH : ");
    Serial.println(pO);

    // jeda program selama satu detik
    delay(1000);
  }else{
    // baca sensor PH
    float phValue = analogRead(PIN_SENSOR_PH);
    float voltage = phValue * (5.0 / 1023.0);
    float phStep = (PH4 - PH7) / 3;
    float pO = 7.00 + ((PH7 - voltage) / phStep);

    // tampilkan nilai sensor PH
    Serial.print("Tegangan : ");
    Serial.print(voltage);
    Serial.print(" -- PH : ");
    Serial.println(pO);

    // jeda program selama setengah detik
    delay(500);
  }
}
