/**
 * @file UltrasonicSensor.ino
 * @brief 超音波センサ制御ライブラリを使って対象物までの距離を計測する
 * @author suzutomo1028@gmail.com
 * @date 2020-10-13 新規作成
 */

#include <Arduino.h>
#include <UltrasonicSensor.h>

UltrasonicSensor sensor(8, 9);

/**
 * @brief 起動時に一度だけ実行するルーチン
 */
void setup() {
  // シリアル通信を開始する
  Serial.begin(9600);
}

/**
 * @brief setupの後に繰り返し実行するルーチン
 */
void loop() {
  // センサから対象物までの距離(cm)を計測する
  float distance = sensor.measureDistance();

  // シリアルモニタに表示する
  Serial.print(distance, 2);
  Serial.print(" cm");
  Serial.println();

  delay(1000);
}