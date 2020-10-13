/**
 * @file UltrasonicSensor.cpp
 * @brief Arduino向けの超音波センサ制御ライブラリ
 * @author suzutomo1028@gmail.com
 * @date 2020-10-13 新規作成
 */

#include "UltrasonicSensor.h"

#define RECV_TIMEOUT  30000 /**< 受信タイムアウト = 30,000(us) */
#define SOUND_SPEED   0.034 /**< 音速 = 340(m/s) = 0.034(cm/us) */

/**
 * @brief コンストラクタ
 * @param trig Trigのピン番号
 * @param echo Echoのピン番号
 */
UltrasonicSensor::UltrasonicSensor(uint8_t trig, uint8_t echo) {
  _trig = trig;
  _echo = echo;
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
  digitalWrite(_trig, LOW);
}

/**
 * @brief デストラクタ
 */
UltrasonicSensor::~UltrasonicSensor() {
  digitalWrite(_trig, LOW);
}

/**
 * @brief センサから対象物までの距離を計測する
 * @return センサから対象物までの距離(cm)
 */
float UltrasonicSensor::measureDistance() {
  // 超音波の発信を停止する
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);

  // 超音波の発信を開始する
  digitalWrite(_trig, HIGH);
  delayMicroseconds(11);

  // 超音波の発信を停止する
  digitalWrite(_trig, LOW);

  // 超音波の発信から反射波の受信までの期間(us)を計測する
  unsigned long duration = pulseIn(_echo, HIGH, RECV_TIMEOUT);

  float distance = 0;
  
  if (duration != 0) {
    // センサから対象物までの距離(cm)を算出する
    distance = (duration / 2) * SOUND_SPEED;
  }

  return distance;
}
