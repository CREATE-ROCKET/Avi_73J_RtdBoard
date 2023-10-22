#include <Arduino.h>
#include <SPICREATE.h>

#include "com/gimbal/receive.h"
#include "com/ground/receive.h"
#include "com/ground/send.h"
#include "domain/setting.h"
#include "write/s25fl512s.h"

TaskHandle_t taskHandle[4];
xTaskHandle xlogHandle0;
// xTaskHandle xlogHandle11;
// xTaskHandle xlogHandle12;

void setup() {
    digitalWrite(flashCS, HIGH);
    digitalWrite(H3LIS331CS, HIGH);
    digitalWrite(ICMCS, HIGH);
    digitalWrite(LPSCS, HIGH);

    Serial.begin(115200);
    while (!Serial)
        ;

    delay(1);

    Serial.println("Start Serial");

    Serial2.begin(9600);
    while (!Serial2)
        ;

    delay(1);

    Serial.println("Start Serial2");

    SPIC1.begin(VSPI, SCK1, MISO1, MOSI1);
    SPIC2.begin(HSPI, SCK2, MISO2, MOSI2);

    Serial.println("SPI");

    delay(1);

    // DataWrite関数を起動
    xTaskCreateUniversal(DataWrite, "DataWrite", 8192, NULL, 1, &taskHandle[0], PRO_CPU_NUM);

    // 通信用関数を起動
    // 受信用
    xTaskCreateUniversal(GimbalReceive, "GimbalReceive", 8192, NULL, 1, &taskHandle[1], APP_CPU_NUM);
    xTaskCreateUniversal(GroundReceive, "GroundReceive", 8192, NULL, 1, &taskHandle[2], APP_CPU_NUM);
    // 送信用
    xTaskCreateUniversal(GroundSend, "GroundSend", 8192, NULL, 1, &taskHandle[3], APP_CPU_NUM);
}

void loop() {}
