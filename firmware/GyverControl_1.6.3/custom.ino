/*
  На данной вкладке можно вручную дописать контроллеру дополнительные возможности.
  - Можно использовать пины D1, D4, D5, D6, D7, D8, D9 как цифровые ВЫХОДЫ и ВХОДЫ
  - Соответствующие каналы нужно отключить из меню дисплея (-> Off), иначе работать не будет
  - В customSetup нужно инициализировать выход как INPUT/OUTPUT
*/
#include <GTimer.h>
#include <MHZ19_uart.h>
#define MHZ19B_RX SENS_1
#define MHZ19B_TX SENS_VCC

MHZ19_uart mhz19;


void customSetup() {
  // инициализация для собственных алгоритмов работы
  Serial.begin(9600);

  delay(5000);
  initMH();
}

void customLoop() {
  // вызывается вместе с основным loop
  EVERY_S(10) {//раз в 10 секунд
    sensorVals[2] = mhz19.getPPM();
    Serial.print("co2: "); Serial.println(sensorVals[2]);
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
