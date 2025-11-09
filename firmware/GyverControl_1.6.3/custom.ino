/*
  На данной вкладке можно вручную дописать контроллеру дополнительные возможности.
  - Можно использовать пины D1, D4, D5, D6, D7, D8, D9 как цифровые ВЫХОДЫ и ВХОДЫ
  - Соответствующие каналы нужно отключить из меню дисплея (-> Off), иначе работать не будет
  - В customSetup нужно инициализировать выход как INPUT/OUTPUT
*/
#include <SoftwareSerial.h>
#include <MHZ19_uart.h>
#define MHZ19B_RX SENS_1
#define MHZ19B_TX SENS_3
SoftwareSerial mySerial(MHZ19B_RX, MHZ19B_TX); // RX, TX
MHZ19_uart mhz19;

#define USE_MHZ19B 1
int CO2ppm = 0;
bool CO2_flag = false;
bool CO2_rst = false;

void customSetup() {
  // инициализация для собственных алгоритмов работы

  mySerial.begin(9600);
  initMH();
}

void customLoop() {
  // вызывается вместе с основным loop
  if (millis() - settingsTimer > 1000) {
    CO2ppm = mhz19.getPPM();
  }
}

void initMH(){
  mhz19.begin(MHZ19B_RX, MHZ19B_TX);
  mhz19.setAutoCalibration(false);
  /*while( mhz19.isWarming() ) {
    Serial.print("MH-Z19 now warming up...  status:");Serial.println(mhz19.getStatus());
    delay(1000);
  }*/
}
