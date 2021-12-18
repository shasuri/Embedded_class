#ifndef __UTILITY_H_
#define __UTILITY_H_

#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"
#include "stm32f10x_usart.h"
#include "sensorConfigure.h"
#include "timerConfigure.h"

typedef struct
{
  uint32_t time;          // log 남긴 시간
  uint16_t temperature;   // 온도
  uint16_t soil_moisture; // 토양 습도
  uint8_t is_pump;        // 펌프 가동 여부
  uint8_t is_vibrate;     // 진동 가동 여부
} Log;

typedef struct
{
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t min;
  uint8_t sec;
} Ts; // Time Struct

void delay(uint32_t s);
void SaveLog(uint8_t is_pump, uint8_t is_vibrate);
Ts ConvertTimeInFormat(uint32_t secs);
void sendLogData(uint16_t month1,         uint16_t month2,
                 uint16_t day1,           uint16_t day2,
                 uint16_t hour1,          uint16_t hour2,
                 uint16_t minute1,        uint16_t minute2,
                 uint16_t second1,        uint16_t second2,
                 uint16_t temperature1,   uint16_t temperature2,
                 uint16_t soil_moisture1, uint16_t soil_moisture2,
                 uint16_t is_pump,        uint16_t is_vibrate);
void sendDataUART1(uint16_t data);
void sendDataUART2(uint16_t data);

#endif