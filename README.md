# Monitoring Aquarium

Created: January 19, 2023 4:42 PM
Status: High🔥

# Dependencies Sensor Suhu

---

1. Download library yang diperlukan🔻
    
    [OneWire](https://www.arduinolibraries.info/libraries/one-wire)
    
    [DallasTemperature](https://www.arduinolibraries.info/libraries/dallas-temperature)
    
2. Install Librarynya
    1. buka Arduino IDE dan pilih menu berikut👇
   
        ![Untitled](https://user-images.githubusercontent.com/89723505/213875396-a4173938-72fa-40af-a12d-070f643de43a.png)
       
    2. pilih file **.zip** yang didownload tadi 👌 
    
    # Skema Rangkaian
    
    ---
    
    ![Koneksikan Kabel seperti gambar diatas 🤟](https://user-images.githubusercontent.com/89723505/213875427-492fe2cb-a5cb-41c7-8b46-23cdb4090070.png)
    
    Koneksikan Kabel seperti gambar diatas 🤟
    
    👉 Kabel Merah  ⇒ Tegangan / Power / Vcc
    
    👉 Kabel Hitam   ⇒ Ground / GND / G
    
    👉 Kabel Kuning ⇒ Data / A
    
    # Program
    
    ---
    
    ```arduino
    // masukkan libraries yang diinstall
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
    	  // Jika tidak melakukan kalibrasi sensor PH (kalibrasi = false). maka kode ini akan berjalan
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
    
      }
    		else{
        // Jika melakukan kalibrasi sensor PH (kalibrasi = true). maka kode ini akan berjalan
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
    ```
    
    pastikan Arduino telah dipilih sesuai dengan tipe Arduino yang digunakan dan juga sudah terkoneksi pada PORT yang benar
    
    ![Untitled](Monitoring%20Aquarium%20d44c4071a56a4dda8401a4478c7bfd8e/Untitled%202.png)
    
    jika semua sudah sesuai. klik tombol ➡️ untuk mengupload program ke Arduino ✨
    
    ![Untitled](Monitoring%20Aquarium%20d44c4071a56a4dda8401a4478c7bfd8e/Untitled%203.png)
    
    untuk melihat output dari program. pilih Serial Monitor atau dengan shortkey ctrl+Shift+M 👌
    
    ![Untitled](Monitoring%20Aquarium%20d44c4071a56a4dda8401a4478c7bfd8e/Untitled%204.png)
    
    > Selamat kamu telah berhasil membuat program Monitoring Suhu dan PH Aquarium🎉
    > 
    
    <aside>
    ❓ Kalo sensor PH nya ga sesuai gmana cara kallibrasinya bang?
    
    </aside>
    
    ### Bagaimana Mengkalibrasi sensor PH
    
    ---
    
    untuk mengkalibrasi sensor PH, harus memiliki cairan PH yang nilainya diketahui 
    
    ![Untitled](Monitoring%20Aquarium%20d44c4071a56a4dda8401a4478c7bfd8e/Untitled.jpeg)
    
    1. ubah program kalibrasi menjadi true pada baris ke 18
        
        `bool kalibrasi = true`
        
    2. Upload program yang baru dengan mengklik tombol ➡️. maka ouputnya bakal kaya gini
        
        ```bash
        Tegangan : 3.04 -- PH : 3.66
        Tegangan : 3.05 -- PH : 3.59
        Tegangan : 3.07 -- PH : 3.44
        Tegangan : 3.08 -- PH : 3.41
        ```
        
    3. Masukkan Sensor kedalam cairan **PH 4** dan catat nilai **Tegangannya** pada baris ke 19 yaitu `#define PH4 3.0`
    4. Masukkan Sensor kedalam cairan **PH 7** dan catat nilai **Tegangannya** pada baris ke 20 yaitu `#define PH7 2.6`
    
    > Selamat kamu telah berhasil mengkalibrasi sensor PH 🎉
    > 
    
    
    kalo ada yang masi bingung atau ada yg mau ditanyain DM aja sini 🤙
    
    [](https://www.instagram.com/allailqadrillah_)
