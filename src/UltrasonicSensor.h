/**
 * @file UltrasonicSensor.h
 * @brief Arduino向けの超音波センサ制御ライブラリ
 * @author suzutomo1028@gmail.com
 * @date 2020-10-13 新規作成
 */

#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include <Arduino.h>

/**
 * @brief 超音波センサクラス
 */
class UltrasonicSensor {
private:
  uint8_t _trig;  /**< Trigのピン番号 */
  uint8_t _echo;  /**< Echoのピン番号 */

public:
  /**
   * @brief コンストラクタ
   * @param trig Trigのピン番号
   * @param echo Echoのピン番号
   */
  UltrasonicSensor(uint8_t trig, uint8_t echo);

  /**
   * @brief デストラクタ
   */
  ~UltrasonicSensor();

  /**
   * @brief センサから対象物までの距離を計測する
   * @return センサから対象物までの距離(cm)
   */
  float measureDistance();
};

#endif /* UltrasonicSensor_h */
